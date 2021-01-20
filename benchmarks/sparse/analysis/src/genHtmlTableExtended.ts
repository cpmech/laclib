import { IReportSet } from './types';
import { genHtmlTableColData } from './genHtmlTableColData';
import { styTable, styTabHeader } from './htmlStyles';
import { genHtmlTableRows } from './genHtmlTableRows';

export const genHtmlTableExtended = (
  matrixName: string,
  reportSet: IReportSet,
  withLinfAx = false,
): string => {
  const labels = Object.keys(reportSet);
  const data = labels.map((label) => reportSet[label]);
  const cols = data.map((reports, j) => genHtmlTableColData(labels[j], reports));
  const rows = genHtmlTableRows(cols, withLinfAx);

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
