import { formatLongNumber } from '@cpmech/util';
import { genHtmlTable } from './genHtmlTable';
import { readReport } from './readReport';
import { HtmlTableShowOptions, IReport, IReportSet, ReadmeOptions, ReadmePlatforms } from './types';

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

const genInfo = (report: IReport): string => {
  const strSym = report.Symmetric ? 'Symmetric matrix' : 'General matrix (unsymmetric)';
  const group = (mat2group as any)[report.MatrixName];
  return `
## ${report.MatrixName} matrix

Reference: https://sparse.tamu.edu/${group}/${report.MatrixName}

* ${strSym}
* Dimension = ${fmtNum(report.NumberOfRows)}
* Number of non-zero values = ${fmtNum(report.NumberOfNonZeros)}
* L-infinity norm of the matrix = ${report.Stats.NormInfA.toExponential(3)}

_results with "${report.Ordering}" ordering:_

`;
};

const four = [1, 2, 3, 4];
const read = readReport;

export const genReadme = (
  matrices: string[],
  plat: ReadmePlatforms = 'open_and_intel',
  options: ReadmeOptions[] = ['seq_omp#'],
  show: HtmlTableShowOptions[] = ['Analyze', 'Factorize'],
): string => {
  let readme = `# Benchmarks using the code for sparse matrices

The code here tests the perfomance of the MUMPS Sparse Solver.
`;

  matrices.forEach((mat) => {
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
    const report = reportSet[' open_seq_omp# '][0];
    const table = genHtmlTable(mat, reportSet, show);
    readme += genInfo(report) + table + '\n\n';
  });

  return readme;
};
