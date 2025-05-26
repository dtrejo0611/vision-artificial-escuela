%Operaciones de valor

clc
close all
clear

f0 = imread('0.bmp');
f1 = rgb2gray(f0);
[filas, columnas] = size(f1);
f3 = zeros(size(f0));
u = 180;
f2 = (f1 >= u);

for i=1:filas
    for j=1:columnas
        if f2(i,j) == 1
            f3(i,j,:) = f0(i,j,:);
        else
            f3(i,j,:) = [0;0;0];
        end
    end
end

figure, imshow(uint8(f3))

% for i=1:filas
%     for j=1:columnas
%         if f1(i,j) >= u
%             f2(i,j)=255;
%         else
%             f2(i,j)=0;
%         end
%     end
% end
% 
% f2 = uint8(f2);

