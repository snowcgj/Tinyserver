/*
 * adder.c - a minimal CGI program that adds two numbers together
 * 这段注释简要说明了文件的用途：这是一个最小化的 CGI 程序，用于将两个数字相加。
 */
/* $begin adder */
#include "../csapp.h"

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;
    /*
    buf 和 p：用于处理查询字符串。
    arg1 和 arg2：存储从查询字符串中提取的两个参数。
    content：构建 HTTP 响应的内容部分。
    n1 和 n2：存储转换后的整数值，初始化为 0。
    */

    /* Extract the two arguments */
    /*
    getenv("QUERY_STRING")：从环境变量中获取查询字符串。例如，URL 为 http://example.com/cgi-bin/adder?123&456，那么 QUERY_STRING 就是 123&456。 就是？后面的

    */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&'); //查找 & 字符，假设查询字符串格式为 arg1&arg2
	*p = '\0';  //  p指向&字符，将 & 替换为 '\0'，将字符串分为两个部分
	strcpy(arg1, buf);   //在遇到字符串的终止字符 '\0' 时自动停止复制
	strcpy(arg2, p+1);  // 找到另一个参数
	n1 = atoi(arg1);
	n2 = atoi(arg2);
    }

    /* Make the response body */
    sprintf(content, "Welcome to add.com: ");
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
    sprintf(content, "%sThanks for visiting!\r\n", content);
    // \r\n<p>：用于在 HTTP 响应中添加换行和段落标签，确保浏览器正确解析和显示内容。
  
    /* Generate the HTTP response */
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    //fflush(stdout)：确保所有输出缓冲区的数据被立即发送到客户端。
    exit(0);
    // exit(0)：正常结束程序。
}
/* $end adder */