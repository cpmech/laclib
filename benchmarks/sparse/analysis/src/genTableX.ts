import { IReportSet } from './types';
import { genColumns } from './genColumns';
import { styTable, styTabHeader, styTabLHeader } from './htmlStyles';

// ro -- results with "open"
// ri -- results with "intel"
export const genTableX = (matrixName: string, reports: IReportSet): string => {
  const all = Object.keys(reports).map((name) => reports[name]);
  const n = all.length;
  const co = genColumns(all[0]);
  const ci = genColumns(all[1]);
  return `<table style="${styTable}">
  <tr>
    <td style="${styTabHeader}">${matrixName}</td>
    <th style="${styTabHeader}">NP or NT 1</th>
    <th style="${styTabHeader}">NP or NT 2</th>
    <th style="${styTabHeader}">NP or NT 3</th>
    <th style="${styTabHeader}">NP or NT 4</th>
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Analyze</th>
    ${co.ana}
  </tr>
  <tr>
    ${ci.ana}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Factorize</th>
    ${co.fac}
  </tr>
  <tr>
    ${ci.fac}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Solve</th>
    ${co.sol}
  </tr>
  <tr>
    ${ci.sol}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Total</th>
    ${co.tot}
  </tr>
  <tr>
    ${ci.tot}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Linf(A*x)</th>
    ${co.normAx}
  </tr>
  <tr>
    ${ci.normAx}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="${n}">Rel Error</th>
    ${co.relErr}
  </tr>
  <tr>
    ${ci.relErr}
  </tr>
</table>
`;
};
