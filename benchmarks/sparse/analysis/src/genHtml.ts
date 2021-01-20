import { maybeWriteFile } from '@cpmech/basic-sys';

export const genHtml = (title: string, body: string, style = ''): string => {
  return `<!DOCTYPE html>
<html>
<head>
<title>${title}</title>
${style}
</head>
<body>
${body}
</body>
</html>
`;
};

export const writeHtml = (filepath: string, title: string, body: string, style = '') => {
  const overwrite = true;
  maybeWriteFile(overwrite, filepath, () => genHtml(title, body, style));
};
