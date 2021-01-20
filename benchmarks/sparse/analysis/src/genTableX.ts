import { IReportSet } from './types';
import { genColumns } from './genColumns';
import { styTable, styTabHeader } from './htmlStyles';
import { genRows } from './genRows';

export const genTableX = (matrixName: string, reports: IReportSet): string => {
  const all = Object.keys(reports).map((name) => reports[name]);

  const cols = all.map((rpts) => genColumns(rpts));
  const rows = genRows(cols);

  const n = all[0].length;
  const nums = Array.from(Array(n).keys());
  const lines = nums.map((i) => `<th style="${styTabHeader}">NP or NT ${i + 1}</th>`);
  const heads = lines.join(`\n    `);

  return `<table style="${styTable}">
  <tr>
    <td style="${styTabHeader}">${matrixName}</td>
    ${heads}
  </tr>${rows}
</table>
`;
};
