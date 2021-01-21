import { IHtmlColData, IHtmlStyles, IReportsAndAnalysis } from './types';

const emojiWorried = ':worried:';

// prettyNum returns a text representation of FP numbers in a nice format
const prettyNum = (x: number, width: number = 5, numDecIfTooLong: number = 3): string => {
  let txt = String(x);
  if (txt.length > width) {
    txt = String(x.toFixed(numDecIfTooLong));
  }
  return txt;
};

// example:
//   label         columns
//  "intel_mpi#" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTableColData = (
  label: string,
  dataset: IReportsAndAnalysis,
  styles?: IHtmlStyles,
  speedupWorryThreshold = 0.75,
): IHtmlColData => {
  // select styles
  const styDat = styles ? styles.tabData : '';
  const styLab = styles ? styles.tabDataLabel : '';

  // function to generate link
  const ahref = (entry: string, link?: string) => (link ? `<a href="${link}">${entry}</a>` : entry);

  // auxiliary
  const { reports, analysis } = dataset;

  // analyze
  const analyzeColumns = reports.map(
    (report) => `<td${styDat}>${report.StepAnalyze.ElapsedTimeString}</td>`,
  );

  // factorize columns
  let factorizeColumns: string[];
  if (analysis) {
    factorizeColumns = reports.map((report, j) => {
      const link = ahref(report.StepFactorize.ElapsedTimeString, report.link);
      const speedup = analysis.fac.speedup[j];
      const blip = speedup <= speedupWorryThreshold ? emojiWorried : '';
      return `<td${styDat}>${link}${blip}<br/>(${prettyNum(speedup)})</td>`;
    });
  } else {
    factorizeColumns = reports.map(
      (report) => `<td${styDat}>${ahref(report.StepFactorize.ElapsedTimeString, report.link)}</td>`,
    );
  }

  // solve columns
  const solveColumns = reports.map(
    (report) => `<td${styDat}>${report.StepSolve.ElapsedTimeString}</td>`,
  );

  // total columns
  const totalColumns = reports.map((report) => `<td${styDat}>${report.TimeSolverString}</td>`);

  // normInfAx columns
  const normInfAxColumns = reports.map((report) => `<td${styDat}>${report.Stats.NormInfAx}</td>`);

  // rel error columns
  const relErrorColumns = reports.map(
    (report) => `<td${styDat}>${report.Stats.RelativeError.toExponential(2)}</td>`,
  );

  // label column
  const sep = '\n    ';
  const labelColumn = `<td${styLab}>${label}</td>${sep}`;

  // label column for Factorize
  const labelColumnF = analysis
    ? `<td${styLab}>${label}<br/>(speedup)</td>${sep}`
    : `<td${styLab}>${label}</td>${sep}`;

  // results
  return {
    Analyze: labelColumn + analyzeColumns.join(sep),
    Factorize: labelColumnF + factorizeColumns.join(sep),
    Solve: labelColumn + solveColumns.join(sep),
    Total: labelColumn + totalColumns.join(sep),
    'Norm(A.x)': labelColumn + normInfAxColumns.join(sep),
    'Rel Error': labelColumn + relErrorColumns.join(sep),
  };
};
