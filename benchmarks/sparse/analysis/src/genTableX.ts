import { IReport } from './report';

const bcolor = '#979797';
const padding = '5px';
const styTable = `border: 1px solid ${bcolor}; border-collapse: collapse;`;
const styTheader = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: center; padding: ${padding};`;
const styLheader = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: right; padding: ${padding};`;
const styData = `border: 1px solid ${bcolor}; border-collapse: collapse; text-align: center; padding: ${padding};`;

// a:analyze, f:factorize, s:solve, t:total
const genColumns = (
  r: IReport[],
): {
  ana: string;
  fac: string;
  sol: string;
  tot: string;
  normAx: string;
  relErr: string;
} => {
  const aa = r.map((d) => `<td style="${styData}">${d.StepAnalyze.ElapsedTimeString}</td>`);
  const ff = r.map((d) => `<td style="${styData}">${d.StepFactorize.ElapsedTimeString}</td>`);
  const ss = r.map((d) => `<td style="${styData}">${d.StepSolve.ElapsedTimeString}</td>`);
  const tt = r.map((d) => `<td style="${styData}">${d.TimeSolverString}</td>`);
  const na = r.map((d) => `<td style="${styData}">${d.Stats.NormInfAx}</td>`);
  const re = r.map((d) => `<td style="${styData}">${d.Stats.RelativeError.toExponential(2)}</td>`);
  return {
    ana: aa.join('\n    '),
    fac: ff.join('\n    '),
    sol: ss.join('\n    '),
    tot: tt.join('\n    '),
    normAx: na.join('\n    '),
    relErr: re.join('\n    '),
  };
};

// ro -- results with "open"
// ri -- results with "intel"
export const genTableX = (
  matrixName: string,
  ro: IReport[],
  ri: IReport[],
  omp = false,
): string => {
  const co = genColumns(ro);
  const ci = genColumns(ri);
  const h = omp ? 'OMP nt' : 'MPI np';
  return `<table style="${styTable}">
  <tr>
    <td style="${styTheader}">${matrixName}</td>
    <th style="${styTheader}">${h} 1</th>
    <th style="${styTheader}">${h} 2</th>
    <th style="${styTheader}">${h} 3</th>
    <th style="${styTheader}">${h} 4</th>
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Analyze</th>
    ${co.ana}
  </tr>
  <tr>
    ${ci.ana}
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Factorize</th>
    ${co.fac}
  </tr>
  <tr>
    ${ci.fac}
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Solve</th>
    ${co.sol}
  </tr>
  <tr>
    ${ci.sol}
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Total</th>
    ${co.tot}
  </tr>
  <tr>
    ${ci.tot}
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Linf(A*x)</th>
    ${co.normAx}
  </tr>
  <tr>
    ${ci.normAx}
  </tr>
  <tr>
    <th style="${styLheader}" rowspan="2">Rel Error</th>
    ${co.relErr}
  </tr>
  <tr>
    ${ci.relErr}
  </tr>
</table>
`;
};
