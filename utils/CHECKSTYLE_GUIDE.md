# Guide for writing Java Codes

We use Checkstyle to enforce a consistent coding style. This document provides a guide for writing Java codes that adhere to the Checkstyle rules.

__What is Checkstyle?__
Just like its name, Checkstyle is a tool that checks your Java code for adherence to a coding standard. It is highly configurable and can be made to support almost any coding standard. It is widely used in the industry and is a must-have tool for any Java developer.

## Exaplanation of the rules

### NewlineAtEndOfFile

Checks whether files end with a new line.

**Correct:**

```java
public class Example1 { // ⤶
// ⤶
} // ⤶ // ok, file ends with a new line.
```

**Incorrect:**

```java
public class Example2 { // ⤶
// ⤶
} // ⤶ // error, file does not end with a new line.
```

### FileLength

Checks the number of lines in a file. The default maximum is 2000 lines.

### LineLength

Checks the length of each line in the file. The default maximum is 80 characters. Here we set it to 120 characters.

**Correct:**

```java
public class Example3 {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example4 {
    public static void main(String[] args) {
        // voilation below 'Line is longer than 80 characters (found 95).'
        System.out.println("THIS IS REALLY LONG LONG LONG LONG LONG AND EXTREMELY LONG LINE");
    }
}
```

### FileTabCharacter

Checks for tab characters in the file. Tabs are not allowed.

**Correct:**

```java
class Example1 {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
class Example2 {
    public static void main(String[] args) {
        // voilation below 'File contains tab characters.'
        System.out.println("Hello, World!");
    }
}
```

### RegexpSingleline

Here we have custom rule to check for trailing spaces in the file.

**Correct:**

```java
class Example1 {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
class Example2 {
    public static void main(String[] args) {
        // voilation below 'Line has trailing spaces.'
        System.out.println("Statement with trailing spaces!");    
        // trailing spaces in the above line                  ^^^^
    }
}
```

### ConstantName

Checks the names of constants. The default pattern is `^[A-Z][A-Z0-9]*(_[A-Z0-9]+)*$`.

**Correct:**

```java
public class Example1 {
    private static final int MAX_VALUE = 100;
}
```

**Incorrect:**

```java
public class Example2 {
    private static final int max_value = 100; // voilation 'Must match pattern '^[A-Z][A-Z0-9]*(_[A-Z0-9]+)*$'.'
}
```

### LocalFinalVariableName

Checks the names of local final variables. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        final int max = 100;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        final int Max = 100; // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
    }
}
```

### LocalVariableName

Checks the names of local variables. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int max = 100;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int Max = 100; // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
    }
}
```

### MemberName

Checks the names of member variables. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    private int max;
}
```

**Incorrect:**

```java
public class Example2 {
    private int Max; // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
}
```

### MethodName

Checks the names of methods. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void Print() { // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
        System.out.println("Hello, World!");
    }
}
```

### PackageName

Checks the names of packages. The default pattern is `^[a-z]+(\.[a-z][a-z0-9]*)*$`.

**Correct:**

```java
package com.example;
```

**Incorrect:**

```java
package com.Example; // voilation 'Must match pattern '^[a-z]+(\.[a-z][a-z0-9]*)*$'.'
```

### ParameterName

Checks the names of parameters. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    public void print(String message) {
        System.out.println(message);
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print(String Message) { // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
        System.out.println(Message);
    }
}
```

### StaticVariableName

Checks the names of static variables. The default pattern is `^[a-z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    private static int max;
}
```

**Incorrect:**

```java
public class Example2 {
    private static int Max; // voilation 'Must match pattern '^[a-z][a-zA-Z0-9]*$'.'
}
```

### TypeName

Checks the names of types. The default pattern is `^[A-Z][a-zA-Z0-9]*$`.

**Correct:**

```java
public class Example1 {
    private int max;
}
```

**Incorrect:**

```java
public class example2 { // voilation 'Must match pattern '^[A-Z][a-zA-Z0-9]*$'.'
    private int max;
}
```

### AvoidStarImport

Checks for star imports. Star imports are not allowed, except for `java.lang` and `java.util`.

**Correct:**

```java
import java.util.List;
```

**Incorrect:**

```java
import java.util.*; // voilation 'Avoid using star imports.'
```

### IllegalImport

Checks for illegal imports. The default illegal package is `sun.*`.

**Correct:**

```java
import java.util.List;
```

**Incorrect:**

```java
import sun.misc.BASE64Encoder; // voilation 'Illegal import of sun class: sun.misc.BASE64Encoder.'
```

### RedundantImport

Checks for redundant imports.

**Correct:**

```java
import java.util.List;
```

**Incorrect:**

```java
import java.util.List; // voilation 'Redundant import from the same package.'
```

### UnusedImports

Checks for unused imports.

**Correct:**

```java
import java.util.List;
```

**Incorrect:**

```java
import java.util.List; // voilation 'Unused import.'
```

### MethodLength

Checks the number of lines in a method. The default maximum is 150 lines.

### ParameterNumber

Checks the number of parameters in a method. The default maximum is 7 parameters.

### EmptyForIteratorPad

Checks for padding around the `:` in an enhanced for loop.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        for (String arg : args) {
            System.out.println(arg);
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        for (String arg: args) { // voilation 'Whitespace is not allowed after ":".'
            System.out.println(arg);
        }
    }
}
```

### GenericWhitespace

Checks for whitespace around generic types.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        List <String> list = new ArrayList<>(); // voilation 'Whitespace is not allowed before "<".'
    }
}
```

### MethodParamPad

Checks for padding around method parameters.

**Correct:**

```java
public class Example1 {
    public void print(String message) {
        System.out.println(message);
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print( String message ) { // voilation 'Whitespace is not allowed before ")"'
        System.out.println(message);
    }
}
```

### OperatorWrap

Checks for wrapping of operators.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int sum = 1 + 2;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int sum = 1
                 + 2; // voilation 'Operator + should be on the previous line.'
    }
}
```

### ParenPad

Checks for padding around parentheses.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int sum = (1 + 2);
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int sum = ( 1 + 2 ); // voilation 'Whitespace is not allowed after "(".'
    }
}
```

### TypecastParenPad

Checks for padding around typecasts.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int sum = (int) 3.14;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int sum = ( int ) 3.14; // voilation 'Whitespace is not allowed after "(".'
    }
}
```

### WhitespaceAfter

Checks for whitespace after certain keywords.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        if(true) { // voilation 'Whitespace is required after "if".'
            System.out.println("Hello, World!");
        }
    }
}
```

### WhitespaceAround

Checks for whitespace around certain operators.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int sum = 1 + 2;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int sum = 1+2; // voilation 'Whitespace is required around "+"'
    }
}
```

### ModifierOrder

Checks the order of modifiers.

The correct order is:

- `public`
- `protected`
- `private`
- `abstract`
- `default`
- `static`
- `sealed`
- `non-sealed`
- `final`
- `transient`
- `volatile`
- `synchronized`
- `native`
- `strictfp`

**Correct:**

```java
public final class Example1 {
    public static final int MAX_VALUE = 100;
    private static final int MIN_VALUE = 0;
    protected static final int DEFAULT_VALUE = 50;
}
```

**Incorrect:**

```java
public final class Example2 {
    final public static int MAX_VALUE = 100; // voilation 'Modifier 'final' must appear before 'public'.'
    static private final int MIN_VALUE = 0; // voilation 'Modifier 'static' must appear before 'private'.'
    protected final static int DEFAULT_VALUE = 50; // voilation 'Modifier 'protected' must appear before 'static'.'
}
```

### RedundantModifier

Checks for redundant modifiers.

**Correct:**

```java
public final class Example1 {
    public static final int MAX_VALUE = 100;
}
```

**Incorrect:**

```java
public final static class Example2 { // voilation 'Redundant 'static' modifier.'
    public static final int MAX_VALUE = 100;
}
```

### AvoidNestedBlocks

Checks for nested blocks.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        if (true) { // voilation 'Nested blocks of code detected.'
            if (true) {
                System.out.println("Hello, World!");
            }
        }
    }
}
```

### EmptyBlock

Checks for empty blocks.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        if (true) { // voilation 'Empty block.'
        }
    }
}
```

### LeftCurly

Checks for the placement of the left curly brace.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2
{
    public static void main(String[] args) { // voilation 'Left curly brace is not preceded by whitespace.'
        System.out.println("Hello, World!");
    }
}
```

### NeedBraces

Checks for the use of braces in certain statements.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        if (true) // voilation 'Statement without braces.'
            System.out.println("Hello, World!");
    }
}
```

### RightCurly

Checks for the placement of the right curly brace.

**Correct:**

```java

public class Example1 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        if (true) {
            System.out.println("Hello, World!");
        } // voilation 'Right curly brace is not followed by whitespace.'
    }
}
```

### EmptyCatchBlock

Checks for empty catch blocks.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        try {
            throw new Exception();
        } catch (Exception e) {
            System.out.println("Caught an exception!");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        try {
            throw new Exception();
        } catch (Exception e) { // voilation 'Empty catch block.'
        }
    }
}
```

### EmptyStatement

Checks for empty statements.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        ; // voilation 'Empty statement.'
        System.out.println("Hello, World!");
    }
}
```

### EqualsHashCode

Checks for the presence of `equals` and `hashCode` methods in classes that override `equals`.

**Correct:**

```java
public class Example1 {
    private int value;

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Example1 example = (Example1) obj;
        return value == example.value;
    }

    @Override
    public int hashCode() {
        return Objects.hash(value);
    }
}
```

**Incorrect:**

```java
public class Example2 {
    private int value;

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Example2 example = (Example2) obj;
        return value == example.value;
    }
    // voilation 'Class does not override equals() in superclass.'
}
```

### HiddenField

Checks for hidden fields.

**Correct:**

```java
public class Example1 {
    private int value;

    public void setValue(int value) {
        this.value = value;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    private int value;

    public void setValue(int value) {
        value = value; // voilation 'Hidden field.'
    }
}
```

### IllegalInstantiation

Checks for illegal instantiations.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<String>(); // voilation 'Illegal instantiation.'
    }
}
```

### InnerAssignment

Checks for inner assignments.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int c = a + b;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int c = a = b; // voilation 'Assignment in operand.'
    }
}
```

### MissingSwitchDefault

Checks for missing `default` cases in `switch` statements.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int value = 1;
        switch (value) {
            case 1:
                System.out.println("One");
                break;
            case 2:
                System.out.println("Two");
                break;
            default:
                System.out.println("Other");
        }
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int value = 1;
        switch (value) {
            case 1:
                System.out.println("One");
                break;
            case 2:
                System.out.println("Two");
                break;
            // voilation 'Switch statement without a default case.'
        }
    }
}
```

### MultipleVariableDeclarations

Checks for multiple variable declarations in a single statement.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int c = 3;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        int a = 1, b = 2, c = 3; // voilation 'Multiple variable declarations.'
    }
}
```

### SimplifyBooleanExpression

Checks for simplified boolean expressions.

**Correct:**

```java
public class Example1 {
    public static void main(String[] args) {
        boolean a = true;
        boolean b = false;
        boolean c = a && b;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static void main(String[] args) {
        boolean a = true;
        boolean b = false;
        boolean c = a == true && b == false; // voilation 'Simplify boolean expression.'
    }
}
```

### SimplifyBooleanReturn

Checks for simplified boolean return statements.

**Correct:**

```java
public class Example1 {
    public static boolean isTrue() {
        return true;
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public static boolean isTrue() {
        if (true) {
            return true;
        } else {
            return false;
        }
    }
}
```

### DesignForExtension

Checks for classes that are not designed for extension.

**Correct:**

```java
public final class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 { // voilation 'Class is not designed for extension.'
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

### FinalClass

Checks for classes that are not final.

**Correct:**

```java
public final class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 { // voilation 'Class is not final.'
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

### InterfaceIsType

Checks for interfaces that are not types.

**Correct:**

```java
public interface Example1 {
    void print();
}
```

**Incorrect:**

```java
public class Example2 { // voilation 'Interface is not a type.'
    void print();
}
```

### VisibilityModifier

Checks for the use of visibility modifiers.

**Correct:**

```java
public class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 {
    void print() { // voilation 'Missing visibility modifier.'
        System.out.println("Hello, World!");
    }
}
```

### OneTopLevelClass

Checks for multiple top-level classes in a single file.

**Correct:**

```java
public class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print() {
        System.out.println("Hello, World!");
    }
}

public class Example3 { // voilation 'More than one top-level class in the file.'
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

### ArrayTypeStyle

Checks for the style of array types.

**Correct:**

```java
public class Example1 {
    private int[] array;
}
```

**Incorrect:**

```java
public class Example2 {
    private int array[]; // voilation 'Array type style.'
}
```

### FinalParameters

Checks for final parameters.

**Correct:**

```java
public class Example1 {
    public void print(final String message) {
        System.out.println(message);
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print(String message) { // voilation 'Parameter is not final.'
        System.out.println(message);
    }
}
```

### TodoComment

Checks for `TODO` comments.

**Correct:**

```java
public class Example1 {
    public void print() {
        System.out.println("Hello, World!");
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print() {
        // TODO: Implement this method // voilation 'TODO comment found.'
    }
}
```

### UpperEll

Checks for the use of upper-case `L` in long literals.

**Correct:**

```java
public class Example1 {
    private long value = 100L;
}
```

**Incorrect:**

```java
public class Example2 {
    private long value = 100l; // voilation 'Use upper case 'L' for long literals.'
}
```

### CommentsIndentation

Checks for the indentation of comments.

**Correct:**

```java
public class Example1 {
    public void print() {
        // This is a comment
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print() {
        //   This is a comment // voilation 'Comment has incorrect indentation level 3, expected is 1.'
    }
}
```

### SuppressionCommentFilter

Checks for suppression comments. Use `// CSOFF: <checkname>` to suppress a check. Use `// CSON: <checkname>` to re-enable a check.

**Correct:**

```java
public class Example1 {
    public void print() {
        // CSOFF: TodoComment
        // TODO: Implement this method
    }
}
```

**Incorrect:**

```java
public class Example2 {
    public void print() {
        // TODO: Implement this method // voilation 'TODO comment found.'
    }
}
```

## Conclusion

These rules are just a subset of the rules that Checkstyle provides. There is no strict rule for this project, but it is recommended to follow these rules to maintain a consistent coding style.
