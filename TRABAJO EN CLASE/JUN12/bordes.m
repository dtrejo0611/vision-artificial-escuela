clc
clear
close all

n=4;

ruta = strcat("ELEMENTOS\", num2str(n), ".jpg");

f0 = imread(ruta);
f1 = imresize(f0,0.1,"nearest");
f2 = rgb2gray(f1);
f3 = Correccion('p',f2,1);
f4 = edge(f3,"canny",[0.1 0.9]);
[filas, columnas] = size(f2);

for i=1:filas
    for j=1:columnas
        if f4(i,j) == 1
            f1(i,j,1) = 0;
            f1(i,j,2) = 255;
            f1(i,j,3) = 0;
        end
    end
end



x = [1:columnas];
y = [1:filas];

fx = sum(f4,1);
fy = sum(f4,2)';

cx = round(sum(x.*fx)/sum(fx));
cy = round(sum(y.*fy)/sum(fy));

f4(cy,cx)=1;

for i=1:filas
    for j=1:columnas
        if f4(i,j) == 1
            break;
        end
    end
    if f4(i,j) == 1
            break;
    end
end

cont=0;
while 1
    cont=cont+1;
    dis(cont) = sqrt((cx-j)^2+(cy-i)^2);
    v = f4(i-1:i+1, j-1:j+1);
    
    dir = [3 2 1;4 0 8; 5 6 7];
    
    d = max(v.*dir,[], 'all');
    
    f4(i,j) = 0;
    
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
end

% figure, imshow(f2)
% figure, imshow(f3)
figure, imshow(f4)
figure, imshow(f1)

figure,plot(dis), axis([1 cont 1 500])

