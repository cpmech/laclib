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

const read = readReport;

export const genReadme = (matrices: string[]): string => {
  let readme = `# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.
`;

  matrices.forEach((mat) => {
    const four = [1, 2, 3, 4];
    const reportSet: IReportSet = {
      [` open_seq_omp# `]: four.map((n) => read(`mumps_${mat}_metis_open_seq_omp${n}`)),
      [`intel_seq_omp# `]: four.map((n) => read(`mumps_${mat}_metis_intel_seq_omp${n}`, true)),
      [` open_mpi1_omp#`]: four.map((n) => read(`mumps_${mat}_metis_open_mpi1_omp${n}`)),
      [`intel_mpi1_omp#`]: four.map((n) => read(`mumps_${mat}_metis_intel_mpi1_omp${n}`, true)),
      [` open_mpi#     `]: four.map((n) => read(`mumps_${mat}_metis_open_mpi${n}`)),
      [`intel_mpi#     `]: four.map((n) => read(`mumps_${mat}_metis_intel_mpi${n}`, true)),
      [` open_mpi#_omp1`]: four.map((n) => read(`mumps_${mat}_metis_open_mpi${n}_omp1`)),
      [`intel_mpi#_omp1`]: four.map((n) => read(`mumps_${mat}_metis_intel_mpi${n}_omp1`, true)),
      [` open_mpi#_omp#`]: [
        read(`mumps_${mat}_metis_open_mpi1_omp1`),
        read(`mumps_${mat}_metis_open_mpi1_omp2`),
        read(`mumps_${mat}_metis_open_mpi2_omp1`),
        read(`mumps_${mat}_metis_open_mpi2_omp2`),
      ],
      [`intel_mpi#_omp#`]: [
        read(`mumps_${mat}_metis_intel_mpi1_omp1`, true),
        read(`mumps_${mat}_metis_intel_mpi1_omp2`, true),
        read(`mumps_${mat}_metis_intel_mpi2_omp1`, true),
        read(`mumps_${mat}_metis_intel_mpi2_omp2`, true),
      ],
    };
    const table = genHtmlTable(mat, reportSet);

    const r0 = reportSet[' open_seq_omp# '][0];
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
