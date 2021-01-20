import { IReport } from './report';
import { genColumns } from './genColumns';
import { styTable, styTabHeader, styTabLHeader } from './htmlStyles';

// a:analyze, f:factorize, s:solve, t:total

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
    <td style="${styTabHeader}">${matrixName}</td>
    <th style="${styTabHeader}">${h} 1</th>
    <th style="${styTabHeader}">${h} 2</th>
    <th style="${styTabHeader}">${h} 3</th>
    <th style="${styTabHeader}">${h} 4</th>
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Analyze</th>
    ${co.ana}
  </tr>
  <tr>
    ${ci.ana}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Factorize</th>
    ${co.fac}
  </tr>
  <tr>
    ${ci.fac}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Solve</th>
    ${co.sol}
  </tr>
  <tr>
    ${ci.sol}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Total</th>
    ${co.tot}
  </tr>
  <tr>
    ${ci.tot}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Linf(A*x)</th>
    ${co.normAx}
  </tr>
  <tr>
    ${ci.normAx}
  </tr>
  <tr>
    <th style="${styTabLHeader}" rowspan="2">Rel Error</th>
    ${co.relErr}
  </tr>
  <tr>
    ${ci.relErr}
  </tr>
</table>
`;
};
