function f1 = svaTransformaciones(f0, dx, dy, A, s)

    f1 = zeros(size(f0));
    [filas, columnas, capas] = size(f0);
    for i=1:filas
        for j=1:columnas
            xt = j+dx;
            yt = i+dy;
            xr = round(s*(xt*cosd(A)+yt*sind(A)));
            yr = round(s*(-xt*sind(A)+yt*cosd(A)));
            if yr>0 && xr>0 && yr<=filas && xr<=columnas
                f1(yr, xr, :) = f0(i, j, :);
            end

        end
    end
    
    f1 = uint8(f1);

end