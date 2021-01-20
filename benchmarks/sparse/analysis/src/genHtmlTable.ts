import { IReport } from './types';
import { genHtmlTableColData } from './genHtmlTableColData';
import { genHtmlTableRows } from './genHtmlTableRows';
import { styTable, styTabHeader } from './htmlStyles';

export const genHtmlTable = (matrixName: string, r: IReport[], omp = false): string => {
  const cols = genHtmlTableColData('', r);
  const rows = genHtmlTableRows([cols]);

  const n = r.length;
  const msg = omp ? 'OMP nt' : 'MPI np';
  const nums = Array.from(Array(n).keys());
  const lines = nums.map((i) => `<th style="${styTabHeader}">${msg} ${i + 1}</th>`);
  const heads = lines.join(`\n    `);

  return `<table style="${styTable}">
  <tr>
    <td style="${styTabHeader}">${matrixName}</td>
    ${heads}
  </tr>${rows}
</table>
`;
};
