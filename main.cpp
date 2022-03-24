#include "CyclicList.h"
#include "Dimensions.h"
#include <iostream>
using namespace std;

const char *menu[4] = {"Choose a task -- 1: Cyclic List, 2: Dimensions\n",
                       "1: push; 2: pop; 3: display; 4: list++; 5: ++list; 6: list--; 7: --list; 8: return to task selection; 9: help\n",
                       "1: fill first instance; 2: fill second instance; 3: help; 4: return to task selection; 5: enter operation selection mode; 6: display first instance; 7: display second instance;\n",
                       "0: operations(ops); 1: +; 2: -; 3: *; 4: /; 5 +=; 6: -=; 7 /=; 8: *=; 9: exit operation selection mode;\nf: toggle mode to do binary ops with a float and a first instance(binary ops use both dims instances as operands by default);\ns: switch float value position(default is second operand)\n"};
bool floatOps = false;
bool firstPos = false;

void in() {
    printf(">> ");
}

void help(int type = 0) {
    printf(menu[type]);
}

char selectType() {
    help();
    in();
    return getchar();
}

int getInt() {
    int result;
    printf("Type the value:\n");
    in();
    scanf("%d", &result);
    return result;
}

float getFloat() {
    float result;
    printf("Type the float:\n");
    in();
    scanf("%f", &result);
    return result;
}

void diff(CyclicList& before, CyclicList& after) {
    printf("before:\n");
    before.display();
    printf("after:\n");
    after.display();
}

char task1() {
    help(1);
    CyclicList l;
    printf("Specify initial length of the list:\n");
    int len = getInt();
    printf("Specify the values themselves:\n");
    for (int i = 0; i < len; i++)
        l.push(getInt());
    while (1) {
        char c = getchar();
        if (c == '\n') 
            in();
        if (c == '1') 
            l.push(getInt());
        else if (c == '2') 
            try {
                printf("%d has been removed\n", l.pop());
            } catch(out_of_range) {
                printf("list is empty\n");
            }
        else if (c == '3')
            l.display();
        else if (c == '4') {
            CyclicList before = l.copy();
            CyclicList after = l++;
            diff(before, after);
        } else if (c == '5') {
            CyclicList before = l.copy();
            CyclicList after = ++l;
            diff(before, after);
        } else if (c == '6') {
            CyclicList before = l.copy();
            CyclicList after = l--;
            diff(before, after);
        } else if (c == '7') {
            CyclicList before = l.copy();
            CyclicList after = --l;
            diff(before, after);
        } else if (c == '8') {
            getchar();
            return selectType();
        }
        else if (c == '9') 
            help(1);
    }
}

char task2() {
    help(2);
    Dims d1, d2, d3;
    while (1) {
        char c = getchar();
        if (c == '\n') 
            in();
        if (c == '1') 
            d1.fill();
        else if (c == '2')
            d2.fill();
        else if (c == '3')
            help(2);
        else if (c == '4') {
            getchar();
            return selectType();
        } 
        else if (c == '5') {
            help(3);
            while (1) {
                char c = getchar();
                float f;
                if (c == '\n') {
                    in();
                }
                if (c == '0') 
                    help(3);
                else if (c == '1')
                    if (floatOps) {
                        f = getFloat();
                        if (firstPos)
                            d3 = f + d1;
                        else
                            d3 = d1 + f;
                    }
                    else
                        d3 = d1 + d2;
                else if (c == '2')
                    if (floatOps) {
                        f = getFloat();
                        d3 = d1 - f;
                    } else
                        d3 = d1 - d2;
                else if (c == '3')
                    if (floatOps) {
                        f = getFloat();
                        d3 = d1 * f;
                    } else
                        d3 = d1 * d2;
                else if (c == '4')
                    if (floatOps) {
                        f = getFloat();
                        d3 = d1 / f;
                    } else
                        d3 = d1 / d2;
                else if (c == '5')
                    if (floatOps) {
                        f = getFloat();
                        d3 += f;
                    } else
                        d3 += d2;
                else if (c == '6')
                    if (floatOps) {
                        f = getFloat();
                        d3 -= f;
                    } else
                        d3 -= d2;
                else if (c == '7')
                    if (floatOps) {
                        f = getFloat();
                        d3 /= f;
                    } else
                        d3 /= d2;
                else if (c == '8')
                    if (floatOps) {
                        f = getFloat();
                        d3 *= f;
                    } else
                        d3 *= d2;
                else if (c == '9') {
                    help(2);
                    break;
                }
                else if (c == 'f')
                    if (!floatOps) {
                        printf("Now working with float number\n");
                        floatOps = true;
                    }
                    else {
                        printf("Now working with second instance\n");
                        floatOps = false;
                    }
                else if (c == 's')
                    if (!firstPos) {
                        printf("Float is first operand now\n");
                        firstPos = true;
                    }
                    else {
                        printf("Float is second operand now\n");
                        firstPos = false;
                    }
                if (c != '\n' && c != 's' && c != 'f' && c != '0') {
                    printf("After operation:\n");
                    if (firstPos && floatOps)
                        printf("f = %.2f\n", f);
                    else {
                        printf("d1 = "); d1.display();
                    }
                    if (!firstPos && floatOps) 
                        printf("f = %.2f\n", f);
                    else {
                        printf("d2 = "); d2.display();
                    }
                    printf("d3 = "); d3.display();
                    d3 = Dims();
                }
            }
        }
        else if (c == '6') {
            printf("d1 = ");
            d1.display();
        }
        else if (c == '7') {
            printf("d2 = ");
            d2.display();
        }
    }
}

int main() {
    char type = selectType();
    while (type) {
        if (type == '1')
            type = task1();
        else if (type == '2')
            type = task2();
        else {
            printf("No such option. Try again.\n");
            getchar();
            type = selectType();
        }
    }
    return 0;
}