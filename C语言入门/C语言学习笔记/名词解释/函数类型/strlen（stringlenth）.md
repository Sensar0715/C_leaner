在 C 语言中，`strlen` 是一个标准库函数，用于计算字符串的长度。它属于 `<string.h>` 头文件，返回字符串中字符的数量，不包括终止符 `'\0'`。

### **函数原型**
```c
#include <string.h>

size_t strlen(const char* str);
```

### **参数**
- **`str`**：指向以空字符（`'\0'`）结尾的字符数组的指针。

### **返回值**
- 返回字符串中字符的数量，不包括终止符 `'\0'`。

### **特点**
1. **计算字符串长度**：
   - `strlen` 计算字符串的长度，直到遇到第一个空字符 `'\0'`。
   - 返回值是 `size_t` 类型，表示字符串的长度。

2. **不包括终止符**：
   - 返回的长度不包括字符串末尾的空字符 `'\0'`。

3. **安全性**：
   - `strlen` 假设输入的字符串是有效的，且以空字符结尾。
   - 如果输入的字符串没有正确终止，可能会导致未定义行为。

### **示例代码**

#### **计算字符串长度**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    size_t length = strlen(str);

    printf("字符串 \"%s\" 的长度是：%zu\n", str, length);

    return 0;
}
```

### **输出**
```
字符串 "Hello, World!" 的长度是：13
```

### **注意事项**

1. **空字符串**：
   - 如果字符串为空（即只包含一个空字符 `'\0'`），`strlen` 返回 0。
   - 例如：
     ```c
     char emptyStr[] = "";
     size_t length = strlen(emptyStr);
     printf("空字符串的长度是：%zu\n", length);  // 输出 0
     ```

2. **未终止的字符串**：
   - 如果字符串没有正确终止（即没有空字符 `'\0'`），`strlen` 会继续读取内存，直到遇到第一个空字符，这可能导致未定义行为。
   - 例如：
     ```c
     char str[10] = "Hello";  // 未正确终止的字符串
     size_t length = strlen(str);  // 未定义行为
     ```

3. **安全性**：
   - 在使用 `strlen` 时，确保字符串是有效的，并且以空字符结尾。
   - 如果需要处理用户输入的字符串，建议使用更安全的函数，如 `strnlen`（在某些平台上可用）。

### **`strnlen` 函数**
`strnlen` 是一个更安全的函数，它允许指定最大长度，避免读取超出预期的内存。

```c
#include <string.h>

size_t strnlen(const char* str, size_t maxlen);
```

- **参数**：
  - `str`：指向以空字符结尾的字符数组的指针。
  - `maxlen`：最大长度限制。

- **返回值**：
  - 返回字符串中字符的数量，但不超过 `maxlen`。

#### **示例代码**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    size_t length = strnlen(str, 10);

    printf("字符串 \"%s\" 的长度（限制为 10）是：%zu\n", str, length);

    return 0;
}
```

### **输出**
```
字符串 "Hello, World!" 的长度（限制为 10）是：10
```

### **总结**
- **`strlen`** 是一个标准库函数，用于计算字符串的长度，返回值是 `size_t` 类型。
- 它计算字符串中字符的数量，直到遇到第一个空字符 `'\0'`。
- 使用 `strlen` 时，确保字符串是有效的，并且以空字符结尾。
- 如果需要更安全的函数，可以使用 `strnlen`，它允许指定最大长度，避免读取超出预期的内存。