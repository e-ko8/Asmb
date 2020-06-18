// Vector&Quaternion 


namespace testStartstask{ 


#ifdef SIMD_OK 
	#include <immintrin.h>
using vec __m128;
#else 
using vec float[4];
#endif	


template <typename A>
class vector4{
    
     public: 

     	  vector4(){}


#ifdef _SIMD_OK_

#endif     	  
     


     private: 
               

 };

}