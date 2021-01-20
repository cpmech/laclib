import { IReport } from './report';
import { genColumns } from './genColumns';
import { styTable, styTabHeader, styTabLHeader, styTabData } from './htmlStyles';

export const genTable = (matrixName: string, r: IReport[], omp = false): string => {
  const sty = styTabData;
  const co = genColumns(r);
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
    <th style="${styTabLHeader}">Analysis</th>
    ${co.ana}
  </tr>
  <tr>
    <th style="${styTabLHeader}">Factorize</th>
    ${co.fac}
  </tr>
  <tr>
    <th style="${styTabLHeader}">Solve</th>
    ${co.sol}
  </tr>
  <tr>
    <th style="${styTabLHeader}">Total</th>
    ${co.tot}
  </tr>
  <tr>
    <th style="${styTabLHeader}">Rel Error</th>
    ${co.relErr}
  </tr>
</table>
`;
};
