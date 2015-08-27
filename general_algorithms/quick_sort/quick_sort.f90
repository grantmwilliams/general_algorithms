program quick
implicit none
real :: start,finish
real, dimension(10) :: array

array = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]

call cpu_time(start)
print *, int(array)
call bubble_sort(array)
print *, int(array)
call cpu_time(finish)

! print time to run program
print'("Elapsed: ", F9.6, " seconds")', finish-start

contains

recursive subroutine quick_sort(a)
  implicit none
  real, intent(inout), dimension(:) :: a

  if (length(a) < 1) then
    return
  end if




end subroutine quick_sort
end program quick
