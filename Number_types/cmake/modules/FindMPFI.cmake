find_package( GMP QUIET )

if( GMP_FOUND )

  if( MPFI_INCLUDE_DIR AND MPFI_LIBRARIES )
    set(MPFI_FOUND TRUE)
  endif( MPFI_INCLUDE_DIR AND MPFI_LIBRARIES )

  find_path(MPFI_INCLUDE_DIR NAMES mpfi.h 
            PATHS ${GMP_INCLUDE_DIR_SEARCH} ENV MPFI_INC_DIR
            DOC "The directory containing the MPFI include files"
           )

  find_library(MPFI_LIBRARIES NAMES mpfi
               PATHS ${GMP_LIBRARIES_DIR_SEARCH} ENV MPFI_LIB_DIR
               DOC "Path to the MPFI library"
               )

  if( MPFI_LIBRARIES ) 
    get_filename_component(MPFI_LIBRARIES_DIR ${MPFI_LIBRARIES} PATH CACHE )
  endif( MPFI_LIBRARIES ) 

  if( NOT MPFI_INCLUDE_DIR OR NOT MPFI_LIBRARIES_DIR )
    include( MPFIConfig OPTIONAL )
  endif( NOT MPFI_INCLUDE_DIR OR NOT MPFI_LIBRARIES_DIR )
 
  include(CGAL_FindPackageHandleStandardArgs)
  
  find_package_handle_standard_args(MPFI "DEFAULT_MSG" MPFI_LIBRARIES MPFI_INCLUDE_DIR )

endif( GMP_FOUND )
