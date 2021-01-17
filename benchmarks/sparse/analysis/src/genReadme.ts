import { formatLongNumber } from '@cpmech/util';
import { genFnkey } from './genFnkey';
import { genTable } from './genTable';
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
  const nums: number[] = [1, 2, 3, 4];

  const strIntel = intel ? ' (Intel)' : '';
  let readme = `# Benchmarks using the code for sparse matrices${strIntel}

The code here tests the perfomance of the MUMPS Sparse Solver.
`;

  matrices.forEach((mat) => {
    const mpiFnkeys = nums.map((n) => genFnkey(mat, n, 0, intel));
    const ompFnkeys = nums.map((n) => genFnkey(mat, 1, n, intel));
    const mpiReports = mpiFnkeys.map((k) => readReport(k));
    const ompReports = ompFnkeys.map((k) => readReport(k));
    const mpiTable = genTable(mat, mpiReports);
    const ompTable = genTable(mat, ompReports, true);
    const r0 = mpiReports[0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const group = (mat2group as any)[mat];
    const [m0, m1, m2, m3] = mpiFnkeys;
    const [o0, o1, o2, o3] = ompFnkeys;
    const info = `
## ${mat} matrix

Reference: https://sparse.tamu.edu/${group}/${mat}

* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}
* L-infinity norm of the matrix = ${r0.Stats.NormInfA.toExponential(3)}

_MPI results with "${r0.Ordering}" ordering:_

${mpiTable}

Log files: [MPI-np1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m0}.txt), 
[MPI-np2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m1}.txt), 
[MPI-np3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m2}.txt), 
[MPI-np4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${m3}.txt)

_OpenMP results with "${r0.Ordering}" ordering:_

${ompTable}

Log files: [OMP-nt1](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o0}.txt), 
[OMP-nt2](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o1}.txt), 
[OMP-nt3](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o2}.txt), 
[OMP-nt4](https://github.com/cpmech/laclib/blob/main/benchmarks/sparse/results/${o3}.txt)

`;

    readme += info;
  });

  return readme;
};
