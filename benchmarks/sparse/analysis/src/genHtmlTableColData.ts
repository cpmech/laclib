import { IHtmlColData, IHtmlStyles, IReportsAndAnalysis } from './types';

// example:
//   label         columns
//  "intel_mpi#" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTableColData = (
  label: string,
  dataset: IReportsAndAnalysis,
  styles?: IHtmlStyles,
): IHtmlColData => {
  // select styles
  const styDat = styles ? styles.tabData : '';
  const styLab = styles ? styles.tabDataLabel : '';

  // function to generate link
  const link = (entry: string, link?: string) => (link ? `<a href="${link}">${entry}</a>` : entry);

  // auxiliary
  const { reports } = dataset;

  // analyze
  const analyze = reports.map(
    (report) => `<td${styDat}>${report.StepAnalyze.ElapsedTimeString}</td>`,
  );

  // factorize columns
  const factorizeColumns = reports.map(
    (report) => `<td${styDat}>${link(report.StepFactorize.ElapsedTimeString, report.link)}</td>`,
  );

  // solve columns
  const solveColumns = reports.map(
    (report) => `<td${styDat}>${report.StepSolve.ElapsedTimeString}</td>`,
  );

  // total columns
  const total = reports.map((report) => `<td${styDat}>${report.TimeSolverString}</td>`);

  // normInfAx columns
  const normInfAxColumns = reports.map((report) => `<td${styDat}>${report.Stats.NormInfAx}</td>`);

  // rel error columns
  const relErrorColumns = reports.map(
    (report) => `<td${styDat}>${report.Stats.RelativeError.toExponential(2)}</td>`,
  );

  // label column
  const labelColumn = `<td${styLab}>${label}</td>\n    `;

  // results
  const sep = '\n    ';
  return {
    Analyze: labelColumn + analyze.join(sep),
    Factorize: labelColumn + factorizeColumns.join(sep),
    Solve: labelColumn + solveColumns.join(sep),
    Total: labelColumn + total.join(sep),
    'Norm(A.x)': labelColumn + normInfAxColumns.join(sep),
    'Rel Error': labelColumn + relErrorColumns.join(sep),
  };
};
