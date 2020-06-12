/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    // #define YYDEBUG 1
    // int yydebug = 1;
    struct symtab{
	    char name[20];
	    char type[20];
            int addr;
            int line;
            char element_type[20];
	};
    int scope=0;
    int address=0;
    int addr_=0;
    int scopes_index[1000];
    int scopes_index_[1000];
    int print_type=0;
    int conversion_t=0;
    int flag=0;
    int local_num=0;
    int integer=0;
    int cmp=0;
    int cmp2=0;
    int cmp3=0;
    float float_num=0;
    char str[100];
    int b;
    int array_t=0;
    char store_ID[100];
    int left_right=0;
    int left_arr=0;
    int c=0;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    struct symtab symtable[10][20];
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(int s);
    static void insert_symbol(char* t,int type,int scope);
    int lookup_symbol(char *a);
    int lookup_type();
    static void dump_symbol(int s);
   
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    char str[50];
    /* ... */
}



/* Token without return */
%token VAR 
%token INT FLOAT BOOL STRING
%token INC DEC
%token GEQ LEQ EQL NEQ
%token '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token LAND LOR
%token NEWLINE PRINT PRINTLN
%token IF ELSE FOR
%token TRUE FALSE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <i_val> BOOL_LIT
%token <str> ID 

/* Nonterminal with return, which need to sepcify type */
%type <i_val> Type TypeName ArrayType 
%type <i_val> Literal Oprand PrimaryExpr UnaryExpr DExpr CExpr BExpr AExpression Expression
%type <str> add_op mul_op cmp_op unary_op assign_op binary_op 
/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%
Program
    : StatementList { dump_symbol(scope);
		      left_right=0;
		    }
;

StatementList
    : StatementList Statement
    | Statement
;
Statement
    : DeclarationStmt NEWLINE 
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | { FILE *f=fopen("hw3.j","a"); fprintf(f,"L_for_begin:\n"); fclose(f); }ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
;
SimpleStmt
    : AssignmentStmt 
    | ExpressionStmt
    | IncDecStmt
;
DeclarationStmt
    : VAR ID Type   { insert_symbol($2,$3,scope);
		      FILE *f=fopen("hw3.j","a");
		      addr_=lookup_symbol($2); 
		      //fprintf(f,"%d\n",array_t);
		      if(array_t==1)
			   fprintf(f,"astore %d\n",addr_);
                      else if(print_type==1)
			   {
				fprintf(f,"ldc 0\n");
                           	fprintf(f,"istore %d\n",addr_);
			   }
                      else if(print_type==2)
			   {
				fprintf(f,"ldc 0.0\n");
                           	fprintf(f,"fstore %d\n",addr_);
			   }
                      else if(print_type==0)
			   {
				fprintf(f,"iconst_0\n");
                           	fprintf(f,"istore %d\n",addr_);
			   }
                      else if(print_type==3)
			   {	
				fprintf(f,"ldc \"\"\n");
                           	fprintf(f,"astore %d\n",addr_);
			   }
                      array_t=0;
		      fclose(f);
		    }
    | VAR ID Type '=' Expression  {     insert_symbol($2,$3,scope); 
					
                                        FILE* f=fopen("hw3.j","a");  
					
					/*fprintf(f,"ldc ");
					if(print_type==1)
						fprintf(f,"%d",integer);
					else if(print_type==2)
					        fprintf(f,"%f",float_num);
					else if(print_type==0)
					{
						if(b==0) fprintf(f,"\"false\"");
						else if(b==1) fprintf(f,"\"true\"");
					}
					else if(print_type==3)
						fprintf(f,"%s",str);

					fprintf(f,"\n");*/
					addr_=lookup_symbol($2);
				        if(print_type==1 && array_t==1)
                                        {
                                                fprintf(f,"newarray int\n");
                                                fprintf(f,"astore %d\n",addr_);
                                        }
					else if(print_type==1 && array_t==1)
					{
						fprintf(f,"newarray float\n");
						fprintf(f,"astore %d\n",addr_);
					}
					else if(print_type==1)
						fprintf(f,"istore %d\n",addr_);
					else if(print_type==2)
						fprintf(f,"fstore %d\n",addr_);
					else if(print_type==0)
						fprintf(f,"istore %d\n",addr_);
					else if(print_type==3)
						fprintf(f,"astore %d\n",addr_);
					array_t=0;
					fclose(f);
		    }
;
AssignmentStmt
    : ID assign_op Expression {              
					//array_t=0;
					printf("%s\n",$2);
					int left_add=0;
					  for(int i=scope;i>=0;i--)
        				  {
            					for(int j=0;j<scopes_index[i];j++)
                				{
                        				if(strcmp(symtable[i][j].name,$1)==0)
                        				{
                                				left_add=symtable[i][j].addr;
                        				}

                			        }
                                          }      

					FILE *f=fopen("hw3.j","a"); 
					
					if(strcmp($2,"ASSIGN")==0)
				       {
					
           					if(print_type==1)
                					fprintf(f,"istore %d\n",left_add);
           					else if(print_type==2)
                					fprintf(f,"fstore %d\n",left_add);
           					else if(print_type==0)
                					fprintf(f,"istore %d\n",left_add);
           					else if(print_type==3)
                					fprintf(f,"astore %d\n",left_add);
        					array_t=0;
					 
					}
					else if(strcmp($2,"ADD_ASSIGN")==0)
					{
						if(print_type==1)
						{
							fprintf(f,"iload %d\n",addr_);
							fprintf(f,"swap\n");
							fprintf(f,"iadd\n");
							fprintf(f,"istore %d\n",left_add);
						}
						else if(print_type==2)
						{
						        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fadd\n");
                                                        fprintf(f,"fstore %d\n",left_add);

						}
						
					}
					else if(strcmp($2,"SUB_ASSIGN")==0)
					{
						if(print_type==1)
						{
							fprintf(f,"iload %d\n",addr_);
							fprintf(f,"swap\n");
							fprintf(f,"isub\n");
							fprintf(f,"istore %d\n",left_add);
						}
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fsub\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

					}
					else if(strcmp($2,"MUL_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"imul\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fmul\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

                                        }
					else if(strcmp($2,"QUO_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"idiv\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
						else if(print_type==2)
                                                {      
                                                        fprintf(f,"fload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"fdiv\n");
                                                        fprintf(f,"fstore %d\n",left_add);

                                                }

                                        }
					else if(strcmp($2,"REM_ASSIGN")==0)
                                        {
                                                if(print_type==1)
                                                {
                                                        fprintf(f,"iload %d\n",addr_);
                                                        fprintf(f,"swap\n");
                                                        fprintf(f,"irem\n");
                                                        fprintf(f,"istore %d\n",left_add);
                                                }
                                        }



					
					fclose(f);

				      }
    | PrimaryExpr '[' Expression ']' assign_op Expression{
								printf("%s\n",$5);
                                        			FILE *f=fopen("hw3.j","a");

                                        			if(strcmp($5,"ASSIGN")==0)
                                       				{
									if(print_type==1)
                                                       	 			fprintf(f,"iastore\n");
									else if(print_type==2)
										fprintf(f,"fastore\n");
                                                			

                                        			}
                                        			else if(strcmp($5,"ADD_ASSIGN")==0)
                                        			{
                                                			if(print_type==1)
                                                			{
                                                        			fprintf(f,"iload %d\n",addr_);
                                                        			fprintf(f,"swap\n");
                                                        			fprintf(f,"iadd\n");
                                                			}

                                        			}
                                        			else if(strcmp($5,"SUB_ASSIGN")==0)
                                        			{
                                        			        if(print_type==1)
                                                			{
                                                        			fprintf(f,"iload %d\n",addr_);
                                                        			fprintf(f,"swap\n");
                                                        			fprintf(f,"isub\n");
                                                			}
                                        			}
                                        			fclose(f);
                                        			left_arr=0;
                                     

                                      			     }

;
assign_op
    : '='{ strcpy($$,"ASSIGN"); } 
    | ADD_ASSIGN { strcpy($$,"ADD_ASSIGN"); }
    | SUB_ASSIGN { strcpy($$,"SUB_ASSIGN"); }
    | MUL_ASSIGN { strcpy($$,"MUL_ASSIGN"); }
    | QUO_ASSIGN { strcpy($$,"QUO_ASSIGN"); }
    | REM_ASSIGN { strcpy($$,"REM_ASSIGN"); }
;

ExpressionStmt
    : Expression
;
IncDecStmt
    : Expression  INC { printf("INC\n");
			FILE *f=fopen("hw3.j","a");
			
			if(print_type==1) 
			{
				fprintf(f,"ldc 1\n");
				fprintf(f,"iadd\n");
				fprintf(f,"istore ");
				fprintf(f,"%d\n",addr_);
			}	
			else if(print_type==2) 
			{
				fprintf(f,"ldc 1.0\n");
				fprintf(f,"fadd\n");
                                fprintf(f,"fstore ");
                                fprintf(f,"%d\n",addr_);

			}
			
			fclose(f);
		      }  
    | Expression  DEC { printf("DEC\n"); 
			FILE *f=fopen("hw3.j","a");
                        
                        if(print_type==1)
                        {
				fprintf(f,"ldc 1\n");
                                fprintf(f,"isub\n");
                                fprintf(f,"istore ");
                                fprintf(f,"%d\n",addr_);
                        }
                        else if(print_type==2)
                        {
				fprintf(f,"ldc 1.0\n");
                                fprintf(f,"fsub\n");
                                fprintf(f,"fstore ");
                                fprintf(f,"%d\n",addr_);

                        }
			fclose(f);

		      } 
;
Type
    : TypeName {$$=$1;}
    | ArrayType {$$=$1;}
;
TypeName
    : INT { $$ = 0; }
    | FLOAT { $$ = 1; }
    | STRING { $$ = 2; }
    | BOOL {$$ = 3; }
;
ArrayType
    : '['{ flag=1;} Expression ']' Type {  $$ = $5+4; 
					   array_t=1;
					   FILE *f=fopen("hw3.j","a");
				           if($5==0)
						fprintf(f,"newarray int\n");  
					   else if($5==1)
						fprintf(f,"newarray float\n");
					   fclose(f);
					 }
;
Block
    : '{' { scope++;  } StatementList '}'{ dump_symbol(scope); if(scopes_index[scope]>0) scopes_index[scope]--; scope--; }
;
IfStmt
    : IF Condition Block{
				FILE *f=fopen("hw3.j","a");
				fprintf(f,"L_if_false_%d:\n",cmp3);
				cmp3++;
				fclose(f);
			}
    | IF Condition Block ELSE IfStmt {
					FILE *f=fopen("hw3.j","a");
                                        fprintf(f,"goto L_if_exit_%d\n",cmp2);
                                        fprintf(f,"L_if_false_%d:\n",cmp3++);
                                        fclose(f);

				     }
					
    | IF Condition Block ELSE{          FILE *f=fopen("hw3.j","a");
                                        fprintf(f,"goto L_if_exit_%d\n",cmp2);
                                        fprintf(f,"L_if_false_%d:\n",cmp3++);
                                        fclose(f);
      }
      Block{
					FILE *f=fopen("hw3.j","a");
					fprintf(f,"L_if_exit_%d:\n",cmp2++);
					fclose(f);
				   }
;
Condition
    : Expression{
			FILE *f=fopen("hw3.j","a");
			//fprintf(f,"ifeq L_if_false\n");
			fprintf(f,"ifeq L_if_false_%d\n",cmp3);
			fclose(f); 
		}
;
ForStmt
    : FOR Condition Block{ FILE *f=fopen("hw3.j","a"); fprintf(f,"goto L_for_begin\n"); fprintf(f,"L_if_false_%d:\n",cmp3);cmp3++; fclose(f); } 
    | FOR ForClause Block
;
ForClause
    : InitStmt ';' Condition ';' PostStmt
;
InitStmt
    : SimpleStmt
;
PostStmt
     : SimpleStmt
;
PrintStmt
    : PRINT '(' Expression ')'   {
                                        if(print_type==0) printf("PRINT bool\n");
                                        else if(print_type==1) printf("PRINT int32\n");
                                        else if(print_type==2) printf("PRINT float32\n");
                                        else printf("PRINT string\n");
					FILE *f=fopen("hw3.j","a");
					if(print_type==0)
					{	
						fprintf(f,"ifne L_cmp_%d\n",cmp++);
                                                fprintf(f,"ldc \"false\"\n");
                                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                                fprintf(f,"ldc \"true\"\n");
                                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                                                fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
					}
					else if(print_type==1)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(I)V\n");

					}
					else if(print_type==2)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(F)V\n");

					}
					else if(print_type==3)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");

					}
					fclose(f);
					
				 }
    | PRINTLN{left_right=1;} '(' Expression ')' { 
					if(print_type==0) printf("PRINTLN bool\n");
					else if(print_type==1) printf("PRINTLN int32\n");
					else if(print_type==2) printf("PRINTLN float32\n");
					else printf("PRINTLN string\n");
					flag=0;
					FILE *f=fopen("hw3.j","a");
					if(print_type==1)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(f,"swap\n");
						fprintf(f,"invokevirtual java/io/PrintStream/println(I)V\n");
					}
					else if(print_type==2)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/println(F)V\n");

					}
					else if(print_type==0)
					{
						fprintf(f,"ifne L_cmp_%d\n",cmp++);
						fprintf(f,"ldc \"false\"\n");
						fprintf(f,"goto L_cmp_%d\n",cmp++);
						fprintf(f,"L_cmp_%d:\n",cmp-2);
						fprintf(f,"ldc \"true\"\n");
						fprintf(f,"L_cmp_%d:\n",cmp-1);
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
						fprintf(f,"swap\n");
						fprintf(f,"invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
					}
					else if(print_type==3)
					{
						fprintf(f,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                                fprintf(f,"swap\n");
                                                fprintf(f,"invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");

					}
					fclose(f);
				 }
;
Expression 
    : AExpression LOR AExpression { printf("LOR\n"); print_type=0;
				    FILE *f=fopen("hw3.j","a");
				    fprintf(f,"ior\n");
				    fclose(f);
				  }
    | AExpression{$$=$1;}
;

AExpression
    : AExpression LAND BExpr { printf("LAND\n"); print_type=0;
			       FILE *f=fopen("hw3.j","a");
                               fprintf(f,"iand\n");
                               fclose(f);

			     }
    | BExpr{$$=$1;}
;

BExpr
    : BExpr cmp_op CExpr { printf("%s\n",$2);  
			   FILE *f=fopen("hw3.j","a");
			   if(strcmp($2,"GTR")==0 && print_type==1)
			   {
				fprintf(f,"isub\n");
				fprintf(f,"ifgt L_cmp_%d\n",cmp++);
				fprintf(f,"iconst_0\n");
				fprintf(f,"goto L_cmp_%d\n",cmp++);
				fprintf(f,"L_cmp_%d:\n",cmp-2);
				fprintf(f,"iconst_1\n");
				fprintf(f,"L_cmp_%d:\n",cmp-1);
			   }
			   else if(strcmp($2,"LSS")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"iflt L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp($2,"GTR")==0 && print_type==2)
			   {
				fprintf(f,"fcmpl\n");
				fprintf(f,"ifgt L_cmp_%d\n",cmp++);
				fprintf(f,"iconst_0\n");
				fprintf(f,"goto L_cmp_%d\n",cmp++);
				fprintf(f,"L_cmp_%d:\n",cmp-2);
				fprintf(f,"iconst_1\n");
				fprintf(f,"L_cmp_%d:\n",cmp-1);
			   }
			   else if(strcmp($2,"LSS")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"iflt L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp($2,"EQL")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifeq L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp($2,"EQL")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifeq L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp($2,"LEQ")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifle L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
                           else if(strcmp($2,"LEQ")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifle L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
			   else if(strcmp($2,"GEQ")==0 && print_type==1)
                           {
                                fprintf(f,"isub\n");
                                fprintf(f,"ifge L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }
                           else if(strcmp($2,"GEQ")==0 && print_type==2)
                           {
                                fprintf(f,"fcmpl\n");
                                fprintf(f,"ifge L_cmp_%d\n",cmp++);
                                fprintf(f,"iconst_0\n");
                                fprintf(f,"goto L_cmp_%d\n",cmp++);
                                fprintf(f,"L_cmp_%d:\n",cmp-2);
                                fprintf(f,"iconst_1\n");
                                fprintf(f,"L_cmp_%d:\n",cmp-1);
                           }

		           

			   fclose(f);
			 }
    | CExpr{$$=$1;}
;
CExpr
    : CExpr add_op DExpr { printf("%s\n",$2);
     				//addr_=lookup_symbol(store_ID); 
				FILE *f=fopen("hw3.j","a");
                                if(strcmp($2,"ADD")==0 && print_type==1) fprintf(f,"iadd\n");
                                else if(strcmp($2,"ADD")==0 && print_type==2) fprintf(f,"fadd\n");
			        else if(strcmp($2,"SUB")==0 && print_type==1) fprintf(f,"isub\n");
				else if(strcmp($2,"SUB")==0 && print_type==2) fprintf(f,"fsub\n");
                                fclose(f);
				

			 }
    | DExpr{$$=$1;}
;
DExpr
    : DExpr mul_op UnaryExpr { printf("%s\n",$2); 
				FILE *f=fopen("hw3.j","a");
				
                                if(strcmp($2,"MUL")==0 && print_type==1) fprintf(f,"imul\n");
                                else if(strcmp($2,"MUL")==0 && print_type==2) fprintf(f,"fmul\n");
                                else if(strcmp($2,"QUO")==0 && print_type==1) fprintf(f,"idiv\n");
                                else if(strcmp($2,"QUO")==0 && print_type==2) fprintf(f,"fdiv\n");
				else if(strcmp($2,"REM")==0 && print_type==1) fprintf(f,"irem\n");
                                fclose(f);

			     }
    | UnaryExpr{$$=$1;}
;
 
UnaryExpr
    : PrimaryExpr{$$=$1;}
    | unary_op UnaryExpr { printf("%s\n",$1); 
			   FILE *f=fopen("hw3.j","a");
                           if(strcmp($1,"NEG")==0 && print_type==1) fprintf(f,"ineg\n");
			   else if(strcmp($1,"NEG")==0 && print_type==2) fprintf(f,"fneg\n");
			   else if(strcmp($1,"NOT")==0) 
			   {
				 fprintf(f,"iconst_1\n");
				 fprintf(f,"ixor\n");
			   }
			   fclose(f);
			 }
;
binary_op
    : LOR
    | LAND
    | cmp_op
    | add_op
    | mul_op
;
cmp_op
    : EQL { strcpy($$,"EQL"); }
    | NEQ { strcpy($$,"NEQ"); }
    | '<' { strcpy($$,"LSS"); }
    | LEQ { strcpy($$,"LEQ"); } 
    | '>' { strcpy($$,"GTR"); }
    | GEQ { strcpy($$,"GEQ"); }
;
add_op
    : '+' { strcpy($$,"ADD"); print_type=1;}
    | '-' { strcpy($$,"SUB"); print_type=1;}
;
mul_op
    : '*' { strcpy($$,"MUL"); }
    | '/' { strcpy($$,"QUO"); print_type=2;}
    | '%' { strcpy($$,"REM"); print_type=2;}
;
unary_op
    : '+' { strcpy($$,"POS"); }
    | '-' { strcpy($$,"NEG"); }
    | '!' { strcpy($$,"NOT"); }
;
PrimaryExpr
    : Oprand {$$=$1;}
    | IndexExpr
    | ConversionExpr
;
Oprand
    : Literal{ $$=$1; c=0;}
    | ID { addr_= lookup_symbol($1); printf("IDENT (name=%s, address=%d)\n",$1,addr_); $$=$1;
           strcpy(store_ID,$1); 
   
           FILE *f=fopen("hw3.j","a");
	   if(array_t==1)
		fprintf(f,"aload %d\n",addr_);

	   else if(print_type==1)
		fprintf(f,"iload %d\n",addr_);
	   else if(print_type==2)
		fprintf(f,"fload %d\n",addr_);
	   else if(print_type==0)
		fprintf(f,"iload %d\n",addr_);
	   else if(print_type==3)
		fprintf(f,"aload %d\n",addr_);
	   array_t=0;
	   
           fclose(f);
	 }
    | '(' Expression ')'
    | TRUE { printf("TRUE\n"); 
	     FILE *f=fopen("hw3.j","a");
	     fprintf(f,"iconst_1\n");
	     fclose(f);
	   }
    | FALSE { printf("FALSE\n");
	      FILE *f=fopen("hw3.j","a");
	      fprintf(f,"iconst_0\n");
	      fclose(f);
  	    }
;

Literal
    : INT_LIT { printf("INT_LIT %d\n",$1); 
		/*if(flag==0)
		{
			print_type=1;
			conversion_t=1;
			
		}*/
		conversion_t=1;
		print_type=1;
		integer=$1;
		$$=$1;
		FILE *f=fopen("hw3.j","a");
		fprintf(f,"ldc %d\n",$1);
		fclose(f);
	      }
    | FLOAT_LIT { printf("FLOAT_LIT %f\n",$1);  
		  /*if(flag==0)
		  {
		    print_type=2;
		    conversion_t=2;
   		  } */	
		 print_type=2;
		 conversion_t=2;	
		 float_num=$1;
		 $$=$1;
		 FILE *f=fopen("hw3.j","a");
		 fprintf(f,"ldc %f\n",$1);
		 fclose(f);
                } 
    | BOOL_LIT { printf("BOOL_LIT %d\n",$1);  
                 /*if(flag==0)
		 {
		   print_type=0;
		   conversion_t=0;
		 }*/
		 b=$1;
		 print_type=0;
		 conversion_t=0;
		 FILE *f=fopen("hw3.j","a");
		 
		 if(b==0) fprintf(f,"iconst_0\n");
		 else if(b==1) fprintf(f,"iconst_1\n");
		 fclose(f);
 }
    | '"' STRING_LIT '"' { printf("STRING_LIT %s\n",$2);
                           /*if(flag==0)
			   {	 
			      print_type=3;
			      conversion_t=3;
			   }*/
			   print_type=3;
			   conversion_t=3;
			   strcpy(str,$2);
			   FILE *f=fopen("hw3.j","a");
			   fprintf(f,"ldc \"%s\"\n",str);
			   fclose(f);
}
;
IndexExpr
    : PrimaryExpr '[' Expression ']'{	FILE *f=fopen("hw3.j","a"); 
					addr_=lookup_symbol(store_ID);
					array_t=1;
                			if(array_t==1 && print_type==1) fprintf(f,"iaload\n");
					else if(array_t==1 && print_type==2) fprintf(f,"faload\n");
                			array_t=0;

					fclose(f);
				    }
;
ConversionExpr
    : Type '(' Expression ')'{
				int t1=$1;
				char aa[3];
				char bb[3];
				if(t1==0) strcpy(aa,"I");
				else if(t1==1) strcpy(aa,"F");
				else if(t1==2) strcpy(aa,"S");
				else if(t1==3) strcpy(aa,"B");	
				if (conversion_t==0) strcpy(bb,"B");
				else if(conversion_t==1) strcpy(bb,"I");
				else if(conversion_t==2) strcpy(bb,"F");
   				else if(conversion_t==3) strcpy(bb,"S");
				printf("%s to %s\n",bb,aa);
				FILE *f=fopen("hw3.j","a");
				if(conversion_t==1 && t1==1)//I to F
					{
						fprintf(f,"i2f\n");
						print_type=2;
					}
				else if(conversion_t==2 && t1==0)// F to I
					{
						fprintf(f,"f2i\n");
						print_type=1;
					}

				fclose(f);
			     }
;
%%

/* C code section */
int main(int argc, char *argv[])
{
    FILE* f=fopen("hw3.j","w");

    fprintf(f,".source hw3.j\n");
    fprintf(f,".class public Main\n");
    fprintf(f,".super java/lang/Object\n");
    fprintf(f,".method public static main([Ljava/lang/String;)V\n");
    fprintf(f,".limit stack 100  ;\n");
    fprintf(f,".limit locals 100 ;\n");
    fclose(f);
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    
    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    
    fclose(yyin);
    f=fopen("hw3.j","a");
    fprintf(f,"	return\n");
    fprintf(f,".end method\n");
    fclose(f);
   

    return 0;
}

static void create_symbol(int s) {
	
}

static void insert_symbol(char* N , int type,int s) {
	int a=-1;
        //for(int i=scope;i>=0;i--)
        //{
            for(int j=0;j<scopes_index[scope];j++)
                {
                        if(strcmp(symtable[scope][j].name,N)==0)
                        {
				a = symtable[scope][j].addr;
                               
                        }
			

                }
	
        //}	
	if(a != -1)
	{
		FILE *f=fopen("hw3.j","a");
	
		fprintf(f,"goto error\n");
		fclose(f);
	}
    else if( type==0 )
	{ 
	    strcpy(symtable[s][ scopes_index[s] ].type,"int32");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if( type==1 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"float32");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if( type==2 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"string");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}		
    else if ( type==3 )
        {
	    strcpy(symtable[s][ scopes_index[s] ].type,"bool");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"-");
	}
    else if ( type==4 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"int32");
	}
    else if ( type==5 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"float32");
	}
    else if ( type==6 )
	{
	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"string");
        }
    else
	{
 	    strcpy(symtable[s][ scopes_index[s] ].type,"array");
	    strcpy(symtable[s][ scopes_index[s] ].element_type,"bool");
	}
    strcpy(symtable[s][ scopes_index[s] ].name,N);
    symtable[s][ scopes_index[s] ].addr=address;
    symtable[s][ scopes_index[s] ].line=yylineno;

    address++;
    scopes_index[s]++;
  
    printf("> Insert {%s} into symbol table (scope level: %d)\n", N, scope);
}

int lookup_symbol(char *a) {
	for(int i=scope;i>=0;i--)
	{
	    for(int j=0;j<scopes_index[i];j++)
		{
			if(strcmp(symtable[i][j].name,a)==0)
			{
				if(strcmp(symtable[i][j].type,"bool")==0)
					{
						 print_type=0;
						 conversion_t=0;
					}					
				else if(strcmp(symtable[i][j].type,"int32")==0)
					 {
						print_type=1;
						conversion_t=1;
					 }
				else if(strcmp(symtable[i][j].type,"float32")==0) 
					 {
						print_type=2;
						conversion_t=2;
					 }	
				else if(strcmp(symtable[i][j].type,"string")==0) 
					 {
						print_type=3;
						conversion_t=3;
					 }
				else if(strcmp(symtable[i][j].type,"array")==0)
					 {	
						array_t=1;
						if(strcmp(symtable[i][j].element_type,"int32")==0)
							print_type=1;
						else if(strcmp(symtable[i][j].element_type,"float32")==0)
							print_type=2;
					 }

				return symtable[i][j].addr;
			}
						   
		}	
	}
}


static void dump_symbol(int s) {
    
    printf("> Dump symbol table (scope level: %d)\n", s);
   
    printf("%-10s%-10s%-0s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0;i<scopes_index[s];i++)
    	printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            i, symtable[s][i].name, symtable[s][i].type, symtable[s][i].addr, symtable[s][i].line, symtable[s][i].element_type );
    
}
