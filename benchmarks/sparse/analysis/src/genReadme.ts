import { formatLongNumber } from '@cpmech/util';
import { genFnkeysXor } from './genFnkey';
import { genHtmlTable } from './genHtmlTable';
import { readReport } from './readReport';

const mat2group = {
  bfwb62: 'Bai',
  inline_1: 'GHS_psdef',
  tmt_unsym: 'CEMW',
  pre2: 'ATandT',
  twotone: 'ATandT',
  Flan_1565: 'Janna',
  av41092: 'Vavasis',
  helm2d03: 'GHS_indef',
  oilpan: 'GHS_psdef',
};

const fmtNum = (n: number): string => formatLongNumber(n.toString());

export const genReadme = (matrices: string[], intel = false): string => {
  const label = intel ? 'intel' : 'open';
  const strIntel = intel ? ' (Intel)' : '';
  let readme = `# Benchmarks using the code for sparse matrices${strIntel}

The code here tests the perfomance of the MUMPS Sparse Solver.
`;

  matrices.forEach((mat) => {
    const mpiFnkeys = genFnkeysXor(mat, false, intel);
    const ompFnkeys = genFnkeysXor(mat, true, intel);
    const mpiReports = mpiFnkeys.map((fnk) => readReport(fnk, intel));
    const ompReports = ompFnkeys.map((fnk) => readReport(fnk, intel));
    const mpiTable = genHtmlTable(mat, { [label]: mpiReports });
    const ompTable = genHtmlTable(mat, { [label]: ompReports });
    const r0 = mpiReports[0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const group = (mat2group as any)[mat];
    const [m0, m1, m2, m3] = mpiFnkeys;
    const [o0, o1, o2, o3] = ompFnkeys;
    const addr = 'https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results';
    const a = intel ? `${addr}/intel` : `${addr}/open`;
    const info = `
## ${mat} matrix

Reference: https://sparse.tamu.edu/${group}/${mat}

* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}
* L-infinity norm of the matrix = ${r0.Stats.NormInfA.toExponential(3)}

_MPI results with "${r0.Ordering}" ordering:_

${mpiTable}

Log files: [mpi1](${a}/${m0}.txt), [mpi2](${a}/${m1}.txt), [mpi3](${a}/${m2}.txt), [mpi4](${a}/${m3}.txt)

_OpenMP results with "${r0.Ordering}" ordering:_

${ompTable}

Log files: [omp1](${a}/${o0}.txt), [omp2](${a}/${o1}.txt), [omp3](${a}/${o2}.txt), [omp4](${a}/${o3}.txt)

`;

    readme += info;
  });

  return readme;
};
