program bubble
implicit none
real :: start,finish
real, dimension(10) :: array

array = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]

call cpu_time(start)
print *, int(array)
call bubble_sort(array)
print *, int(array)
call cpu_time(finish)


print'("Elapsed: ", F9.6, " seconds")', finish-start

contains

subroutine bubble_sort(a)
implicit none
real, intent(inout), dimension(:) :: a
real :: temp
integer :: i, j
logical :: swapped

do j = SIZE(a)-1, 1, -1
swapped = .false.
do i = 1, j
if (a(i) > a(i+1)) then
temp = a(i)
a(i) = a(i+1)
a(i+1) = temp
swapped = .true.
end if
end do
if (.not. swapped) exit
end do
return
end subroutine bubble_sort
end program bubble