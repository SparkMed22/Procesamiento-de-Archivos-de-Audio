#ifndef DEFINE_CONFIRM_H
#define DEFINE_CONFIRM_H

#define CONFIRM_RETURN(expr) \
if (!(expr)) { GlobalReportarError(__FILE__, __LINE__);  return; }

#define CONFIRM_RETVAL(expr, val) \
if (!(expr)) { GlobalReportarError(__FILE__, __LINE__);  return val; }

#define CONFIRM_GOTO(expr, label) \
if (!(expr)) { GlobalReportarError(__FILE__, __LINE__);  goto label; }

#define CONFIRM_NORETURN(expr) \
if (!(expr)) { GlobalReportarError(__FILE__, __LINE__);}

extern void GlobalReportarError(char* pszFile, int  iLine);

#endif