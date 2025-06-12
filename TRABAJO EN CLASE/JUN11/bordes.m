clc
clear 
close all

f0 = imread("circulo.bmp");

f1 = rgb2gray(f0);

f2 = (f1<127);

[filas, columnas] = size(f2);

x = [1:columnas];
y = [1:filas];

fx = sum(f2,1);
fy = sum(f2,2)';

cx = round(sum(x.*fx)/sum(fx));
cy = round(sum(y.*fy)/sum(fy));

f2(cy,cx)=1;

for i=1:filas
    for j=1:columnas
        if f2(i,j) == 1
            break;
        end
    end
    if f2(i,j) == 1
            break;
    end
end

n=0;
while 1
    n=n+1;
    dis(n) = sqrt((cx-j)^2+(cy-i)^2);
    v = f2(i-1:i+1, j-1:j+1);
    
    dir = [3 2 1;4 0 8; 5 6 7];
    
    d = max(v.*dir,[], 'all');
    
    f2(i,j) = 0;
    
    switch (d)
        case 8
            j=j+1;
        case 7
            i=i+1;
            j=j+1;
        case 6
            i=i+1;
        case 5
            i=i+1;
            j=j-1;
        case 4
            j=j-1;
        case 3
            i=i-1;
            j=j-1;
        case 2
            i=i-1;
        case 1
            i=i-1;
            j=j+1; 
        otherwise
            break;
    end

% imshow(f2)
% drawnow
end
figure, imshow(f2)

figure,plot(dis), axis([1 n 1 300])