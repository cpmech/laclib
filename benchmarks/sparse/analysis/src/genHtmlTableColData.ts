import { IReport, IHtmlColData } from './types';
import { styTabData } from './htmlStyles';

// example:
//   label    columns
//  "intel" : [rpt_for_mpi1, rpt_for_mpi2, rpt_for_mpi3, ...]
export const genHtmlTableColData = (
  label: string,
  columns: IReport[],
  sty = styTabData,
): IHtmlColData => {
  const cs = columns;
  const aa = cs.map((c) => `<td style="${sty}">${c.StepAnalyze.ElapsedTimeString}</td>`);
  const ff = cs.map((c) => `<td style="${sty}">${c.StepFactorize.ElapsedTimeString}</td>`);
  const ss = cs.map((c) => `<td style="${sty}">${c.StepSolve.ElapsedTimeString}</td>`);
  const tt = cs.map((c) => `<td style="${sty}">${c.TimeSolverString}</td>`);
  const na = cs.map((c) => `<td style="${sty}">${c.Stats.NormInfAx}</td>`);
  const re = cs.map((c) => `<td style="${sty}">${c.Stats.RelativeError.toExponential(2)}</td>`);
  return {
    label: `<td style="${sty}">${label}</td>`,
    ana: aa.join('\n    '),
    fac: ff.join('\n    '),
    sol: ss.join('\n    '),
    tot: tt.join('\n    '),
    normAx: na.join('\n    '),
    relErr: re.join('\n    '),
  };
};
