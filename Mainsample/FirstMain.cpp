// Simple lib
 // date .... ... ...


#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// msvc:  
// gcc: 

//#define _SIMD_OK_

#ifdef _SIMD_OK_ 
#include <immintrin.h>
using  vec = __m128 ;
#else 
using  vec = float[4];
#endif	


namespace testStartstask{ 


// class vector3{

// };



class vector4{
    
     public: 

     	  vector4(){
#ifdef _SIMD_OK_
     mV = _mm_set_ps(1.0f, 1.0f, 1.0f, 1.0f);
#else 
              mV[0] = 1.0f;
              mV[1] = 1.0f;
              mV[2] = 1.0f;
              mV[3] = 1.0f;

#endif     	  
    } 

          vector4(float a) {
#ifdef _SIMD_OK_
              mV = _mm_set_ps(a, a, a, a);
#else 
              mV[0] = a;
              mV[1] = a;
              mV[2] = a;
              mV[3] = a;

#endif     	  
          }


          vector4(vector4&& a) noexcept {
#ifdef _SIMD_OK_
              mV = _mm_set_ps(a.mV.m128_f32[0], a.mV.m128_f32[1], a.mV.m128_f32[2], a.mV.m128_f32[3]);
#else 
              mV[0] = a.mV[0];
              mV[1] = a.mV[1];
              mV[2] = a.mV[2];
              mV[3] = a.mV[3];

#endif     	  
          }


          vector4(const vector4& a) {
#ifdef _SIMD_OK_
              mV = _mm_set_ps(a.mV.m128_f32[0], a.mV.m128_f32[1], a.mV.m128_f32[2], a.mV.m128_f32[3]);
#else 
              mV[0] = std::move(a.mV[0]);
              mV[1] = std::move(a.mV[1]);
              mV[2] = std::move(a.mV[2]);
              mV[3] = std::move(a.mV[3]);

#endif     	  
          }

      vector4(float a, float b, float c, float d){
#ifdef _SIMD_OK_
     mV = _mm_set_ps(d, c, b, a);
#else 
     mV[0] = a;
     mV[1] = b;
     mV[2] = c;
     mV[3] = d;

#endif     	  
    } 


      ~vector4() {
       
#ifdef _SIMD_OK_
          _mm_setzero_ps();
#else 

#endif 
      }

      vector4 operator=(vector4 cdr) {
          vector4 bacKV; 
          bacKV.mV[0] = cdr.mV[0];
      std::cout << " dsflksdjf == " << bacKV.mV[1] << "\n";
          bacKV.mV[1] = cdr.mV[1];
          bacKV.mV[2] = cdr.mV[2];
          bacKV.mV[3] = cdr.mV[3];


          return bacKV;
      }
       
    vec mV;
};




void checkAll(vector4 vece) {
#ifdef _SIMD_OK_

#else 

    if (vece.mV[0] == 0.0f) {
        vece.mV[0] = 1.0f;
    }

    if (vece.mV[1] == 0.0f) {
        vece.mV[1] = 1.0f;
    }

    if (vece.mV[2] == 0.0f) {
        vece.mV[2] = 1.0f;
    }

    if (vece.mV[3] == 0.0f) {
        vece.mV[3] = 1.0f;
    }

#endif  
}


   vector4 operator+(vector4 a, vector4 b){
   	 vector4 backVect;
 #ifdef _SIMD_OK_
    backVect.mV = _mm_add_ps(a.mV, b.mV); 
#else 
     backVect.mV[0] = a.mV[0] + b.mV[0];
     backVect.mV[1] = a.mV[1] + b.mV[1];
     backVect.mV[2] = a.mV[2] + b.mV[2];
     backVect.mV[3] = a.mV[3] + b.mV[3];
#endif  
    return backVect;
   }

  vector4 operator-(vector4 a, vector4 b){
   	 vector4 backVect;
 #ifdef _SIMD_OK_
    backVect.mV = _mm_sub_ps(a.mV, b.mV); 
#else 
     backVect.mV[0] = a.mV[0] - b.mV[0];
     backVect.mV[1] = a.mV[1] - b.mV[1];
     backVect.mV[2] = a.mV[2] - b.mV[2];
     backVect.mV[3] = a.mV[3] - b.mV[3];
#endif  
    return backVect;
   }


  vector4 operator*(vector4& a, vector4& b) {
      vector4 backVect;
#ifdef _SIMD_OK_
      vector4 bb;
        bb.mV = _mm_mul_ps(a.mV, b.mV);
        std::cout << " my values = " << bb.mV.m128_f32[1]<< "\n";
      backVect.mV = _mm_set_ps(bb.mV.m128_f32[0], bb.mV.m128_f32[1], bb.mV.m128_f32[2], bb.mV.m128_f32[3]);

#else 
      backVect.mV[0] = a.mV[0] * b.mV[0];
      backVect.mV[1] = a.mV[1] * b.mV[1];
      backVect.mV[2] = a.mV[2] * b.mV[2];
      backVect.mV[3] = a.mV[3] * b.mV[3];
#endif  	
      return backVect;
  }


  inline vector4  exponent(vector4 aVw) {
      vector4 backVector;
#ifdef _SIMD_OK_
 
      backVector.mV = _mm_mul_ps(aVw.mV, aVw.mV);
      // backVector.mV = _mm_sqrt_ps(aVw.mV);
#else 
      backVector.mV[0] = powf(aVw.mV[0], 2);
      backVector.mV[1] = powf(aVw.mV[1], 2);
      backVector.mV[2] = powf(aVw.mV[2], 2);
      backVector.mV[3] = powf(aVw.mV[3], 2);
      
#endif
      return backVector;
  }




   inline vector4 sqrtL(vector4& avect) {
         vector4 backVect;
#ifdef _SIMD_OK_
         vector4 bb;
         bb.mV = _mm_sqrt_ps(avect.mV);
          backVect.mV = _mm_set_ps(bb.mV.m128_f32[0], bb.mV.m128_f32[1], bb.mV.m128_f32[2], bb.mV.m128_f32[3]);
#else 
         backVect.mV[0] = sqrtf(avect.mV[0]);
         backVect.mV[1] = sqrtf(avect.mV[1]);
         backVect.mV[2] = sqrtf(avect.mV[2]);
         backVect.mV[3] = sqrtf(avect.mV[3]);
          
#endif
          return backVect;
}



 vector4 operator/(vector4 a, vector4 b){
   	 vector4 backVect;
 #ifdef _SIMD_OK_
    backVect.mV = _mm_div_ps(a.mV, b.mV); 
#else 
    checkAll(b);
    backVect.mV[0] = a.mV[0] / b.mV[0];
    backVect.mV[1] = a.mV[1] / b.mV[1];
    backVect.mV[2] = a.mV[2] / b.mV[2];
    backVect.mV[3] = a.mV[3] / b.mV[3];
#endif  	
    return backVect;
   }


 float lenght(const vector4& vec1,const  vector4& vec2) {
     float backFloat; 
#ifdef _SIMD_OK_
    // backVect.mV = _mm_div_ps(a.mV, b.mV);
     vector4 asd = vec2 - vec1;
     vector4 dle;
     dle.mV = _mm_mul_ps(asd.mV, asd.mV);
    float backFloat1 = dle.mV.m128_f32[0] + dle.mV.m128_f32[1] + dle.mV.m128_f32[2];
     backFloat = sqrtf(backFloat1);
     //vector4 basq = _mm_sqrt_ps(asd);

     
#else 
     checkAll(vec2);
     backFloat = sqrtf(powf(vec2.mV[0] - vec1.mV[0], 2) + powf(vec2.mV[1] - vec1.mV[1], 2) + powf(vec2.mV[2] - vec1.mV[2], 2));
    // backVect = vector4(vec1.mV[0] / vec2.mV[0], vec1.mV[1] / vec2.mV[1], vec1.mV[2] / vec2.mV[2], vec1.mV[3] / vec2.mV[3]);
#endif  
     return backFloat;
   //  return float a = (vec1.mV)
 }


}


using testStartstask::vector4;

struct Star {
public: 
    explicit Star(float r, float m, vector4& pos) {

        radius = r;
        massa = m;
        positions = pos;

      }

    ~Star() = default;

    const float getMass() const {
        return massa;
   }

    const vector4 getPos() const {
        return positions;
    }

    const float getRadi() const {
        return radius;
    }

private: 
    float radius;
    float massa;
    vector4 positions;

};

struct Pacticles {

public: 
    explicit Pacticles(float mas, vector4& ap, float sp) {

        mass = mas;
        std::cout << " const == " << ap.mV[1] << " " << ap.mV[2] << "\n";
        posPart = ap;
        speed = sp;
      }

    ~Pacticles() = default;

    float mass;
    vector4 posPart;
    float speed;

};


constexpr double GRAVITY = 0.000000000066742;
inline float startPlanet = 30;
inline float endPlanet = 300; 
inline float startMass = 600;
inline float endMass = 5000;
inline float startXYZ = 10;
inline float endXYZ = 2000;

inline float pactMassM = 3;
inline float patMassMa = 8;


template <typename A, class B>
const float generateValue(A a, B b) {

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a, b); // distribution in range [1, 6]
    const float sde = static_cast<const float>(dist6(rng));
    std::cout << sde << std::endl;

    return sde;
   // return a + (float)((double)rand() / (RAND_MAX + 1) * (b - a + 1));
   // return  a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (b - a)));
}


template <class R>
void seeVect(R aLos4) {

#ifdef _SIMD_OK_
       std::cout << "a  " << aLos4.mV.m128_f32[0] << " " << aLos4.mV.m128_f32[1] << " " << aLos4.mV.m128_f32[2] << " " << aLos4.mV.m128_f32[3] << " \n";
#else
      std::cout << "a  " << aLos4.mV[0] << " " << aLos4.mV[1] << " " << aLos4.mV[2] << " " << aLos4.mV[3] << " \n";
#endif 
}


template <typename A, typename G>
bool checkCollision(A a, G g) {

    //std::cout << " my posPart and getPOs == " << a.posPart.mV[0] << " " << g.getPos() << " \n";
   // seeVect(a.posPart);
    //std::cout << " this \n";
    //seeVect(g.getPos());
    //std::cout << " my lenght == " << lenght(a.posPart, g.getPos())<< " \n";
   // std::cout << " my radious == " << g.getRadi() << " \n";

    if (lenght(a.posPart, g.getPos()) <= g.getRadi()) {
        return true;
    }
    else {
        return false;
    }

}

 int main(){
 
   std::cout << " my start program  \n"; 
 /*  vector4 aLos = vector4(1.0f, 2.0f, 3.0f, 4.0f);
   vector4 aLos2 = vector4(9.0f, 7.0f, 5.0f, 3.0f);
   vector4 aLos4 = exponent(aLos2); */
   float dqwe = generateValue(20.0f, 300.0f); // 2.3728
   std::cout << " dqwee = " << dqwe << "\n";
//#ifdef _SIMD_OK_
//  
// //  std::cout << " my lenght = " << aLos4 << " \n";
//    std::cout << "a  " << aLos4.mV.m128_f32[0] << " " << aLos4.mV.m128_f32[1] << " " << aLos4.mV.m128_f32[2] << " " << aLos4.mV.m128_f32[3] << " \n";
//#else
//   //std::cout << " my lenght == " << aLos4 << "\n";
//   std::cout << "a  " << aLos4.mV[0] << " " << aLos4.mV[1] << " " << aLos4.mV[2] << " " << aLos4.mV[3] << " \n";
//#endif


   std::vector<Star> lstars;
   lstars.reserve(3);
   std::vector<Pacticles> particleOld;
   std::vector<Pacticles> particleNew;
    
   // create our Stars! 
   for (uint32_t i = 0; i < 3; i++) {

       float startStarsR = generateValue(startPlanet, endPlanet);
       float startStarsMass = generateValue(startMass, endMass);
       vector4 finalPositiStars = vector4(generateValue(startXYZ, endXYZ), generateValue(startXYZ, endXYZ), generateValue(startXYZ, endXYZ), 0.0f);
      
       std::cout << " startStarsR = " << startStarsR << " \n";
       std::cout << " startStarsMass = " << startStarsMass << " \n";
      // std::cout << " finalPositiStars = " << finalPositiStars.mV.m128_f32[0] << " " << finalPositiStars.mV.m128_f32[1]<< " "<< finalPositiStars.mV.m128_f32[3]<< " \n";
       //startPlanet + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (endPlanet - startPlanet)));
       //float startStarsMass = startMass + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (endMass - startMass)));
        

       if (lstars.size() >= 1) {

              // check collisions 
           for (auto& newGen : lstars) {
                  
               if (lenght(finalPositiStars, newGen.getPos()) <= (startStarsR + newGen.getRadi())) {

               }
               else {
                   //Star stars1 = Star(startStarsR, startStarsMass, finalPositiStars);
                   lstars.push_back(Star(startStarsR, startStarsMass, finalPositiStars));
               }
                   
              }
       }
       else {
           //Star stars1 = Star(startStarsR, startStarsMass, finalPositiStars);
           lstars.push_back(Star(startStarsR, startStarsMass, finalPositiStars));
       }
      }

      // check to not collisions 

    //     float mass;
   //vector4 posPart;
   //float speed;

   for (uint32_t i = 0; i <= 1000; i++) {
        
       const float aV1 = generateValue(500.0f, endXYZ);
       const float aV2 = generateValue(200.0f, endXYZ);
       const float aV3 = generateValue(100.0f, endXYZ);
       const float aV4 = generateValue(238.0f, endXYZ);

       std::cout << " ad " << aV1 << " " << aV2 << " " << aV3 << " \n";
        
       Pacticles simpPaticl{ (generateValue(pactMassM, patMassMa) * 0.0001f), vector4(aV1, aV2, aV3, 0.0f), generateValue(0.1f, 23.0f) };
       std::cout << " checks this mass simple= =  " <<simpPaticl.mass << " \n";
       std::cout << " new vector = " << simpPaticl.posPart.mV[0] << simpPaticl.posPart.mV[1] << " \n";
       seeVect(simpPaticl.posPart);
       for (auto myPlanet : lstars) {
           if (!checkCollision(simpPaticl, myPlanet)) {
               particleNew.push_back(simpPaticl);
           }
           else {
            //   std::cout << "fuck check \n";
           }
       }

   }


    


    // Generate simple 10 000 pacticles 
    

    // my work cycles  TODO !!!!! 

     // for 
   vector4 force1;
   vector4 force2;
   vector4 force3;

 //  for (const auto& StartMy : lstars) {
           
     //  const float simpleA = (GRAVITY * el.mass * StartMy.getMass());
      
   const int sizeStars = lstars.size();
   std::vector<vector4> myVectoForce;



       std::chrono::time_point startMytime = std::chrono::steady_clock::now();

       const int sizeStar2 = lstars.size();
        // cycles 10 000
       std::vector<vector4> forces;
       forces.reserve(sizeof(sizeStar2));
       for (uint32_t k = 0; k < 10000; k++) {
             
           for (auto& packW : particleNew) {
               
               for (auto& plane : lstars) {
                    
                     const vector4 force = vector4(GRAVITY * packW.mass * plane.getMass()) / vector4(sqrtL(packW.posPart - plane.getPos()));
                     forces.push_back(force);
               }

                  
                
                

            }
            
       }


       const auto diff434 = std::chrono::high_resolution_clock::now() - startMytime;

       std::cout << " my time s == " << (size_t)std::chrono::duration<double, std::milli>(diff434).count() << " \n";

 return 1;
 }
