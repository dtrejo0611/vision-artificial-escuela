function [PM,PC,PP,Fs,Fb,HISTO]=estadisticas(R)
HISTO=zeros(1,256);
[filas,columnas]=size(R);

for i=1:filas
    for j=1:columnas
        HISTO(1,R(i,j)+1)=HISTO(1,R(i,j)+1)+1;
    end
end

[MM,PM]=max(HISTO);
PC=sum([0:255].*HISTO)/sum(HISTO);
Fs=0;

for i=2:256
    if HISTO(i)>0&&HISTO(i-1)==0
        Fs=i;
        break;
    end
end

Fb=255;

for i=256:-1:2
    if HISTO(i)==0&&HISTO(i-1)>0
        Fb=i;
        break;
    end
end

PP=Fs+(Fb-Fs)/2;

end