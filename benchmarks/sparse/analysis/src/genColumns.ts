import { IReport } from './report';
import { styTabData } from './htmlStyles';

export const genColumns = (
  r: IReport[],
  sty = styTabData,
): {
  ana: string;
  fac: string;
  sol: string;
  tot: string;
  normAx: string;
  relErr: string;
} => {
  const aa = r.map((d) => `<td style="${sty}">${d.StepAnalyze.ElapsedTimeString}</td>`);
  const ff = r.map((d) => `<td style="${sty}">${d.StepFactorize.ElapsedTimeString}</td>`);
  const ss = r.map((d) => `<td style="${sty}">${d.StepSolve.ElapsedTimeString}</td>`);
  const tt = r.map((d) => `<td style="${sty}">${d.TimeSolverString}</td>`);
  const na = r.map((d) => `<td style="${sty}">${d.Stats.NormInfAx}</td>`);
  const re = r.map((d) => `<td style="${sty}">${d.Stats.RelativeError.toExponential(2)}</td>`);
  return {
    ana: aa.join('\n    '),
    fac: ff.join('\n    '),
    sol: ss.join('\n    '),
    tot: tt.join('\n    '),
    normAx: na.join('\n    '),
    relErr: re.join('\n    '),
  };
};
