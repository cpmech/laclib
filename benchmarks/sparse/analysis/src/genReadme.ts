import { formatLongNumber } from '@cpmech/util';
import { analyzeData } from './analyzeData';
import { genHtmlTable } from './genHtmlTable';
import { readReport } from './readReport';
import {
  TableField,
  IReport,
  IReportSet,
  PlatOption,
  PlatToolset,
  DescribePlatOption,
  IHtmlStyles,
  IReportsAndAnalysis,
} from './types';

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
## ${(mat2group as any)[report.MatrixName]} / ${report.MatrixName} matrix

Reference: https://sparse.tamu.edu/${group}/${report.MatrixName}

* ${strSym}
* Dimension = ${fmtNum(report.NumberOfRows)}
* Number of non-zero values = ${fmtNum(report.NumberOfNonZeros)}
* L-infinity norm of the matrix = ${report.Stats.NormInfA.toExponential(3)}

_results with "${report.Ordering}" ordering:_

`;
};

const four = [1, 2, 3, 4];

const read = (matrix: string, option: PlatOption, m = '#', n = '#', toolset: PlatToolset) => {
  const opt = option.replace('#', m).replace('#', n);
  return readReport(`mumps_${matrix}_metis_${toolset}_${opt}`, toolset);
};

const readFour = (
  matrix: string,
  option: PlatOption,
  toolset: PlatToolset,
): IReportsAndAnalysis => {
  let reports: IReport[];
  if (option === 'mpi#_omp#') {
    reports = [
      read(matrix, option, '1', '1', toolset),
      read(matrix, option, '1', '2', toolset),
      read(matrix, option, '2', '1', toolset),
      read(matrix, option, '2', '2', toolset),
    ];
  } else {
    reports = four.map((n) => read(matrix, option, `${n}`, '#', toolset));
  }
  const analysis = analyzeData(reports);
  return { reports, analysis };
};

export const genReadme = (
  matrices: string[],
  toolsets: PlatToolset[] = ['open', 'intel'],
  options: PlatOption[] = ['seq_omp#'],
  fields: TableField[] = ['Analyze', 'Factorize'],
  styles?: IHtmlStyles,
): string => {
  // description of options (cases)
  const desc = options.map((option) => `- **${option}** ${DescribePlatOption[option]}`).join('\n');

  // top of page
  let readme = `# Benchmarks using the code for sparse matrices

The code here tests the performance of the MUMPS Sparse Solver.

The **case** keywords in the tables have the following meanings:

${desc}

The values in blue are links to the log files.

`;

  // loop over each matrix name
  matrices.forEach((matrix) => {
    const reportSet: IReportSet = {};

    // load results
    options.forEach((option) => {
      toolsets.forEach((toolset) => {
        reportSet[`${toolset}_${option}`] = readFour(matrix, option, toolset);
      });
    });

    // extract the first report
    const firstKey = Object.keys(reportSet)[0];
    const report = reportSet[firstKey].reports[0];

    // generate html table
    const table = genHtmlTable(matrix, reportSet, fields, styles);

    // update
    readme += genInfo(report) + table + '\n\n';
  });

  // results
  return readme;
};
