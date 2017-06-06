- bug1

用例："http://www.microsofttranslator.com/bv.aspx?from=&to=zh-chs&xxx&query=http://hnujug.com/"

期望结果：“http://hnujug.com/"

运行结果：“”

原因：108行，token.nextString('=') ; 使用‘=’分割，导致分割的key="xxx&query",和期望的key="query"不一致，所以无法获得正确结果

解决方案：在获得的带有‘&’的key的基础上，截取最后一个‘&’之后的字符串作为新的key

- bug2

用例："http://www.microsofttranslator.com/bv.aspx?from=&to=zh-chs&xxx&query=&yyy"

期望结果：“”

运行结果：“&yyy"

原因：116行，token.getReadableSize();把以‘&’开头的字符串计算在合法的字符串中

解决方案：判断，匹配的key的等号后面的字符串如果以‘&’开头，则可读长度为0，使得返回为“”