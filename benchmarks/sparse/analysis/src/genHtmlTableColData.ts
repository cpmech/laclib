import { IReport, IHtmlColData } from './types';
import { styTabData, styTabDataTAR } from './htmlStyles';

// example:
//   label    columns
//  "intel" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTableColData = (
  label: string,
  columns: IReport[],
  sty = styTabData,
  styLabel = styTabDataTAR,
): IHtmlColData => {
  const k = (entry: string, link?: string) => (link ? `<a href="${link}">${entry}</a>` : entry);
  const cs = columns;
  const aa = cs.map((c) => `<td style="${sty}">${c.StepAnalyze.ElapsedTimeString}</td>`);
  const ff = cs.map(
    (c) => `<td style="${sty}">${k(c.StepFactorize.ElapsedTimeString, c.link)}</td>`,
  );
  const ss = cs.map((c) => `<td style="${sty}">${c.StepSolve.ElapsedTimeString}</td>`);
  const tt = cs.map((c) => `<td style="${sty}">${c.TimeSolverString}</td>`);
  const na = cs.map((c) => `<td style="${sty}">${c.Stats.NormInfAx}</td>`);
  const re = cs.map((c) => `<td style="${sty}">${c.Stats.RelativeError.toExponential(2)}</td>`);
  const l = `<td style="${styLabel}">${label}</td>\n    `;
  return {
    Analyze: l + aa.join('\n    '),
    Factorize: l + ff.join('\n    '),
    Solve: l + ss.join('\n    '),
    Total: l + tt.join('\n    '),
    'Norm(A.x)': l + na.join('\n    '),
    'Rel Error': l + re.join('\n    '),
  };
};
