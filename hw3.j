.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100  ;
.limit locals 100 ;
ldc 0
istore 0
L_for_begin:
ldc 0
istore 0
iload 0
ldc 10
isub
iflt L_cmp_0
iconst_0
goto L_cmp_1
L_cmp_0:
iconst_1
L_cmp_1:
ifeq L_if_false_0
iload 0
ldc 1
iadd
istore 0
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
ldc 3
newarray int
astore 1
aload 1
ldc 0
ldc 1
ldc 2
iadd
iastore
aload 1
ldc 1
aload 1
ldc 0
iaload
ldc 1
isub
iastore
aload 1
ldc 2
aload 1
ldc 1
iaload
ldc 3
idiv
iastore
aload 1
ldc 2
iaload
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
ldc 3
ldc 4
ldc 5
ldc 8
ineg
iadd
imul
isub
ldc 10
ldc 7
idiv
isub
ldc 4
ineg
ldc 3
irem
isub
ifgt L_cmp_2
iconst_0
goto L_cmp_3
L_cmp_2:
iconst_1
L_cmp_3:
iconst_1
iconst_1
ixor
iconst_0
iconst_1
ixor
iconst_1
ixor
iand
ior
ifne L_cmp_4
ldc "false"
goto L_cmp_5
L_cmp_4:
ldc "true"
L_cmp_5:
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
ldc 3
newarray float
astore 2
aload 2
ldc 0
ldc 1.100000
ldc 2.100000
fadd
fastore
aload 2
ldc 0
faload
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
ldc 0
istore 3
ldc 2
iload 3
swap
iadd
istore 3
L_for_begin:
iload 3
ldc 0
isub
ifgt L_cmp_6
iconst_0
goto L_cmp_7
L_cmp_6:
iconst_1
L_cmp_7:
ifeq L_if_false_0
aload 1
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
aload 1
ldc 1
isub
istore 1
aload 1
ldc 0
ifeq L_if_false_0
ldc 3.140000
fstore 4
fload 4
ldc 1.000000
fadd
f2i
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
ldc "If x != "
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
fload 4
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
goto L_if_exit_0
L_if_false_0:
ldc 6.600000
fstore 5
ldc "If x == "
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
ldc 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
fload 5
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
L_if_exit_0:
ldc 0
istore 6
L_for_begin:
ldc 1
istore 6
iload 6
ldc 3
isub
ifle L_cmp_8
iconst_0
goto L_cmp_9
L_cmp_8:
iconst_1
L_cmp_9:
ifeq L_if_false_1
iload 6
ldc 1
iadd
istore 6
aload 1
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "*"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 6
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "="
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
aload 1
iload 6
imul
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\t"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto L_for_begin
L_if_false_1:
	return
.end method
