import { formatLongNumber } from '@cpmech/util';
import { genHtmlTable } from './genHtmlTable';
import { readReport } from './readReport';
import { IReportSet } from './types';

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

export const genReadme = (matrices: string[]): string => {
  let readme = `# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.
`;

  matrices.forEach((mat) => {
    const four = [1, 2, 3, 4];
    const genReportSet = (key = 'open'): IReportSet => ({
      [`${key}_seq_omp# `]: four.map((n) => readReport(`mumps_${mat}_metis_${key}_seq_omp${n}`)),
      [`${key}_mpi1_omp#`]: four.map((n) => readReport(`mumps_${mat}_metis_${key}_mpi1_omp${n}`)),
      [`${key}_mpi#     `]: four.map((n) => readReport(`mumps_${mat}_metis_${key}_mpi${n}`)),
      [`${key}_mpi#_omp1`]: four.map((n) => readReport(`mumps_${mat}_metis_${key}_mpi${n}_omp1`)),
      [`${key}_mpi#_omp#`]: [
        readReport(`mumps_${mat}_metis_${key}_mpi1_omp1`),
        readReport(`mumps_${mat}_metis_${key}_mpi1_omp2`),
        readReport(`mumps_${mat}_metis_${key}_mpi2_omp1`),
        readReport(`mumps_${mat}_metis_${key}_mpi2_omp2`),
      ],
    });
    const reportSet = { ...genReportSet('open') }; //, ...genReportSet('intel') };
    const table = genHtmlTable(mat, reportSet);

    const r0 = reportSet['open_seq_omp# '][0];
    const strSym = r0.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
    const group = (mat2group as any)[mat];

    const info = `
## ${mat} matrix

Reference: https://sparse.tamu.edu/${group}/${mat}

* ${strSym}
* Dimension = ${fmtNum(r0.NumberOfRows)}
* Number of non-zero values = ${fmtNum(r0.NumberOfNonZeros)}
* L-infinity norm of the matrix = ${r0.Stats.NormInfA.toExponential(3)}

_results with "metis" ordering:_

${table}

`;

    readme += info;
  });

  return readme;
};
