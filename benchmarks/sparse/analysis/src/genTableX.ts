import { IReportSet } from './types';
import { genColumns } from './genColumns';
import { styTable, styTabHeader } from './htmlStyles';
import { genRows } from './genRows';

export const genTableX = (
  matrixName: string,
  reportSet: IReportSet,
  withLinfAx = false,
): string => {
  const labels = Object.keys(reportSet);
  const data = labels.map((label) => reportSet[label]);
  const cols = data.map((reports, j) => genColumns(labels[j], reports));
  const rows = genRows(cols, withLinfAx);

  const n = data[0].length;
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
