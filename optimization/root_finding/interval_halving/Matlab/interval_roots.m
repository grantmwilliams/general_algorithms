function [ r ] = interval_roots(left_bound, right_bound, max_iter, eps_step, eps_abs )
    % Check that that neither end-point is a root
    % and if f(a) and f(b) have the same sign, throw an exception.

    if ( f(left_bound) == 0 )
	r = left_bound;
	return;
    elseif ( f(right_bound) == 0 )
	r = right_bound;
	return;
    elseif ( f(left_bound) * f(right_bound) > 0 )
        error( 'f(a) and f(b) do not have opposite signs' );
    end

    % We will iterate N times and if a root was not
    % found after N iterations, an exception will be thrown.

    for k = 1:max_iter
        % Find the mid-point
        c = (left_bound + right_bound)/2;

        % Check if we found a root or whether or not
        % we should continue with:
        %          [a, c] if f(a) and f(c) have opposite signs, or
        %          [c, b] if f(c) and f(b) have opposite signs.

        if ( f(c) == 0 )
            r = c;
            return;
        elseif ( f(c)*f(left_bound) < 0 )
            right_bound = c;
        else
            left_bound = c;
        end

        % If |b - a| < eps_step, check whether or not
        %       |f(a)| < |f(b)| and |f(a)| < eps_abs and return 'a', or
        %       |f(b)| < eps_abs and return 'b'.

        if ( right_bound - left_bound < eps_step )
            if ( abs( f(left_bound) ) < abs( f(right_bound) ) && abs( f(left_bound) ) < eps_abs )
                r = left_bound;
                return;
            elseif ( abs( f(right_bound) ) < eps_abs )
                r = right_bound;
                return;
            end
        end
    end

    error( 'the method did not converge' );
end

function y = f(x)
    y = x.^3 -2;
end