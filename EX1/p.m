function[m]= p(operand)
%Prioritze the operands
if operand=='+' || operand == '-'
    m=1;
elseif operand=='*' ||  operand == '/'
        m=2;
else
    error('you dumbass!')

end
end