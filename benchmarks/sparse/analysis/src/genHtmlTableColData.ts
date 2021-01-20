import { IReport, IColumns } from './types';
import { styTabData } from './htmlStyles';

export const genHtmlTableColData = (label: string, r: IReport[], sty = styTabData): IColumns => {
  const aa = r.map((d) => `<td style="${sty}">${d.StepAnalyze.ElapsedTimeString}</td>`);
  const ff = r.map((d) => `<td style="${sty}">${d.StepFactorize.ElapsedTimeString}</td>`);
  const ss = r.map((d) => `<td style="${sty}">${d.StepSolve.ElapsedTimeString}</td>`);
  const tt = r.map((d) => `<td style="${sty}">${d.TimeSolverString}</td>`);
  const na = r.map((d) => `<td style="${sty}">${d.Stats.NormInfAx}</td>`);
  const re = r.map((d) => `<td style="${sty}">${d.Stats.RelativeError.toExponential(2)}</td>`);
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
