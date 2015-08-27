! Fortran90 code for k-d tree function
function kdtree2_create(input_data,dim,sort,rearrange) Result (mr)
  ! create a tree from input data(1:d,1:N)
  ! if PRESENT(dim), use this dimensionality.
  ! if (sort .eqv. .true.) then sort all search results by increasing distance.
  real, target :: input_data(:,:)
  integer, intent(in), optional :: dim
  logical, intent(in), optional :: sort
  logical, intent(in), optional :: rearrange

  Type (kdtree2), Pointer :: mr ! the master record for the tree.

  subroutine kdtree2_destroy(tp)
    ! Deallocates all memory for the tree, except input data matrix
    Type (kdtree2), Pointer :: tp
  end subroutine kdtree2_destroy

  subroutine kdtree2_n_nearest(tp,qv,nn,results)
    ! Find the 'nn' vectors in the tree nearest to 'qv' in euclidean norm
    ! returning their indexes and distances in 'indexes' and 'distances'
    ! arrays already allocated passed to this subroutine
    type (kdtree2), pointer       :: tp
    real, target, intent(in)      :: qv(:)
    integer, intent(in)           :: nn
    type(kdtree2_result), target  :: results(:)
  end subroutine kdtree2_n_nearest

  subroutine kdtree2_n_nearest_around_point(tp,idxin,correltime,nn,results)
    ! Find the 'nn' vectors in the tree nearest to point 'idxin',
    ! with correlation window 'correltime', returning results in
    ! results(:), which must be pre-allocated upon entry.
    type (kdtree2), pointer       :: tp
    integer, intent(in)           :: idxin, correltime, nn
    type(kdtree2_result), target  :: results(:)
  end subroutine kdtree2_n_nearest_around_point

  subroutine kdtree2_r_nearest_around_point(tp,indxin,correltime,r2,nfound,nalloc,results)
    type(kdtree2), pointer        :: tp
    real, target, intent(in)      :: idxin, correltime, nalloc
    real, intent(in)              :: r2
    integer, intent(out)          :: nfound
    type(kdtree2_result), target  :: results(:)
  end subroutine kdtree2_r_nearest_around_point

  
