#!/usr/bin/python3
from function import Function

if __name__ == "__main__":
    # other_expression = "((!((x1^x2)->x1))v(x1^(x2vx323)))"
    expression = "(!((x1vx3)^(!(x2~x3))))"
    function = Function(expression)
    print(function)
