!Interval Halving Fortran
program interval_halving
implicit none
real :: start, finish

call cpu_time(start)
call ans()
call cpu_time(finish)

print'("Elapsed: ", F9.6, " seconds")', finish - start

contains
    subroutine ans()
    integer :: MAX_ITER = 10000
    integer :: TOL = 0.00001
    real :: L = -10, R = 10
    real :: M
    real :: fun_val
    integer :: iter

        do iter = 1, MAX_ITER, 1

            M = (L + R)*0.5 !New Midpoint
            fun_val = f(M)

        if(fun_val == 0 .or. ((R-L)*0.5) < TOL)then
            print'("After ", I5.2, " iterations ", F9.6)', iter
            print'("A root was found at: ", F9.6)', M

            exit
        end if

        if((fun_val) * f(L) < 0) then
            R = M
        else
            L = M

        end if

        end do

        if(iter == MAX_ITER)then
            write(*,*) 'The solution does not converge or iterations are not sufficient'
        end if
    end subroutine ans

    real function f(x)
    implicit none
    real, intent(in) :: x

    f = x*x*x - 4*x - 9

    end function f

end program interval_halving