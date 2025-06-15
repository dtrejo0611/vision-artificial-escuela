clc
clear
close all
% n=0;
for n=0:4
    rutaF = strcat("BD\Rectangulo\", num2str(n), ".mat");
    
    load(rutaF);
    [filas,columnas]=size(dis);
    figure,plot(dis), axis([1 columnas 1 (max(dis)+50)])
end