clc
clear
close all

f0 = imread("0.bmp");

f1 = double(rgb2gray(f0));

% f1 = double(imnoise(rgb2gray(f0),'salt & pepper'));

[filas, columnas] = size(f1);

for T=1:2:101
    tipo = 'M';
    switch tipo
        case 'P'
            Filtro = (1/T^2)*ones(T,T);
        case 'B'
            n = T-1;
            for r=0:n
                nCr(r+1)=factorial(n)/(factorial(r)*factorial(n-r));
            end
            
            Filtro = (nCr'*nCr)./sum(nCr'*nCr,"all");
    
        otherwise
    
    end
    
    f2 = zeros(filas,columnas);
    
    inicio = (T+1)/2;
    fin = (T-1)/2;
    for i=inicio:filas-fin
        for j=inicio:columnas-fin
            V = f1(i-fin:i+fin,j-fin:j+fin);
            if tipo ~= 'M'
                f2(i,j)=sum(Filtro.*V,'all');
            else
                f2(i,j) = median(V,"all");
            end
    
        end
    end
    
    % figure, imshow(uint8(f1))
    imshow(uint8(f2))
    title(num2str(T))
    drawnow
end