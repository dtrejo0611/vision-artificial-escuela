clc
clear
close all
T = 3;
n = T-1;
for r=0:n
    nCr(r+1)=factorial(n)/(factorial(r)*factorial(n-r));
end

Filtro = (nCr'*nCr)./sum(nCr'*nCr,"all");