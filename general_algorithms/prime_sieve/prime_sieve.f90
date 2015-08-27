program primes
implicit none
real :: start,finish

call cpu_time(start)
call sieve()
call cpu_time(finish)

print'("Elapsed: ", F9.6, " seconds")', finish-start

contains
    subroutine sieve()
    implicit none
    integer, parameter :: max = 2000000
    integer(8) :: i, j, k, imax, jmax, numprime,sums
    logical :: sieve_array(max)
    sums = 0 ! Initialize sum to 0

    sieve_array(:) = .TRUE. ! Scalar assignment eliminates do loop
    numprime = 0
    imax = floor(sqrt(real(max)))

    do i = 2, imax
        if (sieve_array(i)) then
            jmax = max/i
            sieve_array(2*i:i*jmax:i) = .FALSE. ! Masked assignment eliminates do loop
        end if
    end do

! *** Sums Primes *** !
    do i = 2,max
        if (sieve_array(i))then
            sums = sums + i
        end if
    end do

    print *, 'Sum of primes below ', max
    print *, sums

    end subroutine sieve
end program primes