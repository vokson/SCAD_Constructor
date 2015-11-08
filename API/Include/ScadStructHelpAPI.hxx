#ifndef ScadStructHelpApiFLAG_H
#define ScadStructHelpApiFLAG_H

#pragma pack(push,1)

typedef double * lpDouble;

struct UnitsAPI  {
	char Name[10];
	float coef;       };
typedef	  const UnitsAPI * LPCUnitsAPI;
struct CNodeApi
{
	LPCSTR  		Text;	//	CSCSTR        Text;
	double  		x, y, z;
	BYTE 			Flag;	 
};

typedef	  CNodeApi * LPCNodeApi;

struct CElemInfApi
{
	LPCSTR  	Text;	//	CSCSTR        Text;
	UINT        QuantityNode;
	UINT      * Node;

	WORD        TypeElem;            // ��� ��������
	BYTE        IsDeletet;		     // ����� ��������
	UINT        TypeRigid;           /// ��� ���������
	UINT        NumInsert;           // ����p ������ ����.���.
	UINT        NumSysCoord;         // ����p ������ ���. ����p.
	UINT        NumSysCoordEffors;   // ����p ������ ���. ����p.���.���p.
	UINT        NumBed;              // ����p ������ ������������� �������.
	UINT        NumStress;         // ��������������

	struct {  UINT Quantity;  UINT * Pointer;  } * Hole;     // ���������  

};

struct SCAD_IDENT
{
	char          Text[256];
	int           Quantity;
	double        Data[32];
};

struct SCAD_SECTION {
	char            Name[512];      //  ��� ���� ��������� 
	int             NumRgd;         //  ����� ���� ��������� � ��������� ���������� ��� ������� �������
	int             Group;          //  0-7 - ���������������� �������
                                        //  201-230 - ������� �� ��������������
                                        //  231 - 234 - ��������� ������� �� ��������������   
                                        //  99 - ��������� ������� ������
                                        //  199 - ������ ������������ �������
	int             GroupSection;   //  0-7 - ���������������� �������
                                        //  201-230 - ������� �� ��������������
                                        //  231 - 234 - ��������� ������� �� ��������������   
	
	int             QuantityGeom;   //  ��� ����������������� ������ ��� �������
	double          Geom[200];      //  ������� ����������������� �������
	
	char            NameBase[_MAX_PATH];  // ��� ���� ��������������
	char            FileSection[16];    // ��� ������ ���� ��������������
	int             NumString;          // ����� ������ � ������
	
	int             QuantityDataSection;  //  ����� �������������� ������ ��� ��� ��������� �������
	double          DataDoubleSection[4]; //  �������������� ������ ��� ��� ��������� �������:
                                              //  ��� ���������� ��� ������������,
            	                              //  ����� ���������� ��� ������ �� Z � �.�.
	
	int             YesConstructor;       //  ������ �� ������������ �������
	char            NameFileConstructor[_MAX_PATH]; //  ��� ����� ��� ������������
	double          DataConstructor[13];      //  ������ � ���������� 
	
	int             TypeElem;             //  ��� ���������� ������� ��� ��������: 1-5, 10
	int             YesN;                 //  ���� �������������� ��� ������
	double          N;                    //  �������� ��������������
	
	double          ema[6];               //  EF,EIY,EIZ,GKP,GFY,GFZ  �������� ��� ���������� ������������
	
	double          E;                   //  ������ ���������
	double          ro;                  //  ���������
	double          nu;                  //  ����������� ��������
	
};

//  ����� �������� �������
#define SgDirectX      0x0001
#define SgDirectY      0x0002
#define SgDirectZ      0x0004
#define SgDirectUX     0x0008
#define SgDirectUY     0x0010
#define SgDirectUZ     0x0020
#define SgDirectAX     0x0040
#define SgDirectAY     0x0080
#define SgDirectAZ     0x0100
#define SgDirectBX     0x0200
#define SgDirectBY     0x0400
#define SgDirectBZ     0x0800
#define SgDirectCX     0x1000
#define SgDirectCY     0x2000
#define SgDirectCZ     0x4000

//  ����� ��������
#define SgUnknown     0 
#define SgForceX      1
#define SgForceY      2
#define SgForceZ      3
#define SgForceUX     4
#define SgForceUY     5
#define SgForceUZ     6

#define SgEffortsN      0x000000000000000001
#define SgEffortsMk     0x000000000000000002 
#define SgEffortsM      0x000000000000000004
#define SgEffortsQ      0x000000000000000008
#define SgEffortsMy     0x000000000000000010
#define SgEffortsQz     0x000000000000000020
#define SgEffortsMz     0x000000000000000040
#define SgEffortsQy     0x000000000000000080
#define SgEffortsNX     0x000000000000000100
#define SgEffortsNY     0x000000000000000200
#define SgEffortsNZ     0x000000000000000400
#define SgEffortsTXY    0x000000000000000800
#define SgEffortsTXZ    0x000000000000001000
#define SgEffortsTYZ    0x000000000000002000
#define SgEffortsMX     0x000000000000004000
#define SgEffortsMY     0x000000000000008000
#define SgEffortsMXY    0x000000000000010000
#define SgEffortsQX     0x000000000000020000
#define SgEffortsQY     0x000000000000040000
#define SgEffortsQXY    0x000000000000080000
#define SgEffortsRZP    0x000000000000100000
#define SgEffortsNEQ    0x000000000000200000
#define SgEffortsN1     0x000000000000400000
#define SgEffortsN2     0x000000000000800000
#define SgEffortsAlfa   0x000000000001000000
#define SgEffortsWG     0x000000000002000000
#define SgEffortsRX     0x000000000004000000
#define SgEffortsRY     0x000000000008000000
#define SgEffortsRZ     0x000000000010000000
#define SgEffortsRUX    0x000000000020000000
#define SgEffortsRUY    0x000000000040000000
#define SgEffortsRUZ    0x000000000080000000
#define SgEffortsRAX    0x000000000100000000
#define SgEffortsRAY    0x000000000200000000
#define SgEffortsRAZ    0x000000000400000000
#define SgEffortsRBX    0x000000000800000000
#define SgEffortsRBY    0x000000001000000000
#define SgEffortsRBZ    0x000000002000000000
#define SgEffortsRCX    0x000000004000000000
#define SgEffortsRCY    0x000000008000000000
#define SgEffortsRCZ    0x000000010000000000

typedef enum : BYTE
{
	ApiGroupUndefined	    = 0,
	ApiGroupRod			= 1,
	ApiGroupPlate			= 2,
	ApiGroupVolume			= 3,
	ApiGroupSpecial		= 4,
	ApiGroupAxecymmetric	= 5,
}  ApiGroupType;

typedef enum : BYTE
{
	ApiLocalSystemCoord       	 =  0,   // 
	//  �������, ������������ ���
	ApiRodCornerInDegrees  	 =  1,   // ���� � ��������
	ApiRodCornerInRadians	     =  2,  //  ���� � ��������
	ApiRodPointFocusAxecY   	 =  3,   // �����, �� ������� �������������  ��. ��� Y
	ApiRodVectorFocusAxecY      =  4,   // ������, �� ������� ������������� ��. ��� Y
	ApiRodPointFocusAxecZ 		 =  5,   // �����, �� ������� �������������  ��. ��� Z
	ApiRodVectorFocusAxecZ  	 =  6,   // ������, �� ������� ������������� ��. ��� Z
	//  �������, ������� ���
	ApiRodPointFocusGeomAxecY   =  7,   // �����, �� ������� �������������  ����. ��� Y
	ApiRodVectorFocusGeomAxecY  =  8,   // ������, �� ������� ������������� ����. ��� Y
	ApiRodPointFocusGeomAxecZ 	 =  9,   // �����, �� ������� �������������  ����. ��� Z
	ApiRodVectorFocusGeomAxecZ  = 10,   // ������, �� ������� ������������� ����.  ��� Z
	//  �����
	ApiPlateAxecX               = 16,  // ����������� � � ���������� ��
	ApiPlatePointFocusAxecX     = 17,  // ����������� � �� �����
	ApiPlatePointFocusCentersAxecX = 18,  // ����������� � �� ����� �� ������
	ApiPlateAxecY               = 19,  // ����������� Y � ���������� ��
	ApiPlatePointFocusAxecY     = 20,  // ����������� Y �� �����
	ApiPlatePointFocusCentersAxecY = 21,  // ����������� Y �� ����� �� ������
	//  Volume
	ApiVolumeAxecXY             = 32,  // ����������� �, Y 
	ApiVolumeAxecXZ             = 33,  // ����������� �, Z 
	ApiVolumeAxecYZ             = 34,  // ����������� Y, Z 
	ApiVolumeCornersInDegrees   = 35,  // ���� ������ � ��������
	ApiVolumeCornersInRadians   = 36,  // ���� ������ � ��������
	ApiVolumeCylinderTwoPointsZ = 37,  // �������. �������� ��� ����� �� ��� �� � �� 
	ApiVolumeCylinderPointsAndVectorZ = 38,  // �������. �������� ����� � ����������� 
	ApiVolumeSphereCentreAndPointY    = 39,  // �����. �������� ����� � �����, �� ������� ������������� ��� Y 
	ApiVolumeSphereCentreAndVectorY   = 40,  // �����. �������� �������� ����� � ����������� ��� Y
}  ApiSystemCoord;

typedef enum : BYTE
{
	ApiF�rceNode              =  0,	// ���������������
	ApiF�rceNodeDisplace      =  1,	// �������� ����������� (���������������)
	ApiF�rceNodeSpecial       =  2,	// ���������������

	ApiForcePointLocal        =  5,	// ��������������� 
	ApiForceEvenlyLocal       =  6,	// �������� - ��������, �������� - ���������, volume - �������� ��� ���������
	ApiForceTrapezLocal       =  7,	// �������� - ��������, �������� - ���������, volume - ��������
	ApiForceTempLocal         =  8,  
	ApiForceLineEvenlyLocal   =  9,	// ��������
	ApiForceLineTrapezLocal   = 10,	// ��������  

	ApiForceNullElem 		  = 11,	// �����/����

	ApiForcePointGlobal       = 15,	// ��������������� 
	ApiForceEvenlyGlobal      = 16,	// �������� - ��������, �������� - ���������, volume - �������� ��� ���������
	ApiForceTrapezGlobal      = 17,	// �������� - ��������, �������� - ���������, volume - ��������
	ApiForceTempTrapez        = 18,  // ����������� � ����� ��������: dta1 dtb1 dta2 dtb2 ...
	ApiForceLineEvenlyGlobal  = 19,	// �������� 
	ApiForceLineTrapezGlobal  = 20, 	// �������� 

	ApiForcePointPartLocal    = 45,   // � ����� ����� ��� �������� 	// ���������������
	ApiForceEvenlyLocalIns    = 46,	 // �������� - ��������. �������� � ������ ������� �������
	ApiForceTrapezPartLocal   = 47,	 // ��������    
	ApiForcePointPartGlobal   = 55,   // ���������������
	ApiForceEvenlyGlobal_INS  = 56,	 // �������� - ��������. �������� � ������ ������� �������
	ApiForceTrapezPartGlobal  = 57,	 // ��������   

	ApiForcePointMass         = 85,   //  ����� ����. �� ���� ������������
	ApiForceEvenlyMass        = 86,   //  ����� �/� �� ���� ������������

	ApiForceTempUnif          = 88, 

	ApiForceWeight            = 96,	// �������� - ��������, �������� - ���������, volume - ��������
	ApiForceWeightIns         = 116,	// �������� - ��������. �������� � ������ ������� �������

}   ApiForceType;

struct   ApiRSU_ADD { BYTE Type;  UINT NumNagr;  };

struct APIRsuNew  {
	WORD       TypeLoad;          // ��� ���������
	WORD       ModeLoad;          // ��� ����������
	WORD       Sign;              // variable sign
	WORD       Crane;             // ����� ����� 
	WORD       CraneRegime;       // ������ ������� ������ �����, 1-8
	WORD       NoActive;          // �� ��������   
	double     CoeffSafetyFactor;  //  ����������� ���������� �� ��������
	double     LongTimeLoadComponent;  // ���� ���������� ������������
	double     Coeff[16];          // koef-s  rsu
};

typedef enum : BYTE
{
    ApiDYN_NO     =   0,  // �������
    ApiDYN_TIME   =   1,  // �������������� �� �������
    ApiDYN_LS     =   2,  // ����������� ������������ �������� �������� (������ ��� ������������ � �������) ( 252 )
    ApiDYN_LN_LS  =   3,  // ������������/������ + ����������� ������������ �������� �������� ( 253 )
    ApiDYN_LB_LS  =   4,  // ������������/������ + ����������� ������������ �������� �������� ( 253 )
    ApiDYN_MASS   =   5,  // �����
    ApiDYN_FORM   =  11,  // �����
    ApiDYN_STAB   =  12,  // ����� ������ ������������
    ApiDYN_RD     =  13,  // �������������� �����
    ApiDYN_RI     =  14,  // ����������� �����
    ApiDYN_FORMX  =  15,  // �����������������
    ApiDYN_FORMY  =  16,  // �����������������
    ApiDYN_FORMZ  =  17,  // �����������������
    ApiDYN_FORMUX =  18,  // �����������������
    ApiDYN_FORMUY =  19,  // �����������������
    ApiDYN_FORMUZ =  20,  // �����������������

    ApiDYN_SD     =  21,  // ������������ ��������� ( ����� ���������, �� ������ )
    ApiDYN_SI     =  22,  // ������������ ��������� �� �������������� � ����������� �����
    ApiDYN_LS_SD  =  31,  // ����������� + ������������ ���������.
    ApiDYN_LN_SD  =  32,  // ������������/������ + ������������ ��������� ( 251 ) 
    ApiDYN_LS_SI  =  34,  // ����������� + ������������ ���������.
    ApiDYN_LN_SI  =  35,  // ������������/������ + ������������ ��������� ( 251 ) 
    ApiDYN_LB_SD  =  37,  // ������ + ������������ ��������� ( 251 ) 
    ApiDYN_LB_SI  =  39,  // ������ + ������������ ��������� ( 251 ) 
    ApiDYN_LN_TIME=  41,  // �������������� �� �������
    ApiDYN_LB_TIME=  42,  // �������������� �� �������
    ApiResultTypeUndefined =0xFF
}   ApiLoadingStringType;


struct ApiLoadingData {
	BYTE     TypeInf;            // RESULT_DATA
	BYTE     TypeLoad;           // 
	WORD     TypeEnvelope;       // 1-200, 200
	WORD     NumLoad;
	WORD     NumSchemUnite;      //  ����� ������ �������� 
	WORD     NumLoadSchemUnite;  //  ����� ���������� � ������ �������� 
	WORD     NumStep;            //  ��� ��� ����������� �������� 
	WORD     NumFixedStep;       // ����� �/� ���������� � ������� �������� 
	UINT32   QuantityForm;
	UINT32   NumForm;
	double   Value;              //  �����. ��������, ����� ��� ��������
	float    ProcMassX;        //  ��� ����� ��������� ������� ����
	float    ProcMassY;        //  ��� ����� ��������� ������� ����
	float    ProcMassZ;        //  ��� ����� ��������� ������� ����
	LPCTSTR  Name;
	double * Comb;
};

typedef ApiLoadingData * lpApiLoadingData;

struct  ApiElemEffors 
{
	UINT           NumElem; 
	BYTE           QuantityUs; 
	const BYTE   * TypeUs;
	BYTE           QuantityPoint;
	WORD           QuantityPointLayers;
	WORD           QuantityLoading;
	WORD           QuantityComb;
	BYTE           IsComb; 
	size_t         MaxSizeUs; 
	size_t         QuantityDataUs; 
	double       * Us;
	size_t         MaxSizeUsComb; 
	size_t         QuantityDataUsComb; 
	double       * UsComb;
};

struct  ApiElemRsuStr 
{
	UINT    NumElem;      // ����� ��������. ��� ���������� �� �����, ���������� � HEAD_USIL
	BYTE    NumPoint;      // ����� ������� ��������. ��� ���������� �� ����� ��� ��������
	BYTE    NumPointElem;  // ����� ������� ��������
	BYTE    NumColumn;   	// ����� �������
	BYTE    GroupRsu;     // ������� ���������� 0 - ��� ����������, 1 - ������ ���������� �����									
	//					  2 - �����������,    3 - ������ ���������� ����� �����������									 
	WORD    NumCrit;   	// ����� ��������
	WORD    QuantityCoef;
	BYTE    YesSeism;     // ������� ������� ������������ ��������
	BYTE    YesSpec;      // ������� ������� ����������� �� ������������ �������� 
	BYTE    YesCrane;     // ������� ������� ������
	BYTE    YesTransport; // ������� ������������ �������� � ��������
	BYTE    Res[4];
	float * Us;
	WORD  * NumLoad;
	float * Coef;
	float   Value; 
};

struct  ApiElemRsu 
{
	UINT    NumElem;     // ����� �� ��� ������ ���������� ���
	BYTE    TypeUnif;    // ��� ���������� ���
	WORD    GroupUnif;  // 
	BYTE    TypeConstr;  // ��� ����������� �� ������ � ���
	BYTE    QuantityPoint;
	BYTE    QuantityUs;
	UINT    LengthData;  // ����� ������
	UINT    Quantity;    // ����� ����������
	ApiElemRsuStr * Str;
};

typedef enum
#ifndef _lint
		: BYTE
#endif
	{
		API_RESULT_UNDEFINED   = 0, 
		API_RESULT_LOAD        = 11, 
		API_RESULT_LOAD_COMB   = 12, 
		API_RESULT_MODE        = 13, 
		API_RESULT_STABIL      = 14, 
		API_RESULT_STABIL_COMB = 15, 

		API_RESULT_MASS        = 21,
		
		API_RESULT_FRAGMENT      = 33,
		API_RESULT_FRAGMENT_COMB = 34,
		API_RESULT_FRAGMENT_LINK = 35,
		API_RESULT_FRAGMENT_LINK_COMB = 36,
	} API_RESULT_DATA;  

struct ApiArmElemRod
{
	UINT      PartNo; // ����� �������
	double    L_percent; // ����� ������� � ��������� �� �����
	UINT      IsS1D2; // S1 ����� ��� ��������� ��������
	UINT      IsS2D2; // S2 ����� ��� ��������� ��������
	UINT      IsSw; // ���� ���������
	UINT      IsS34; // ���� S3,S4
	UINT      dS1L1_1; // ������ ������� S1
	UINT      nS1L1_1; // ���������� �������� S1
	UINT      dS2L1_1; // ������ ������� S2
	UINT      nS2L1_1; // ���������� �������� S2

	UINT      dS1L1_2; // ������ ������� S1 (IsS1D2==SCTRUE)
	UINT      nS1L1_2; // ���������� �������� S1 ������� �������� (IsS1D2==SCTRUE)
	UINT      dS2L1_2; // ������ ������� S2 (IsS2D2==SCTRUE)
	UINT      nS2L1_2; // ���������� �������� S2 ������� �������� (IsS2D2==SCTRUE)
	UINT      dS3L1_1; // ������� S3
	UINT      nS3L1_1; // ���������� �������� S3
	UINT      dS4L1_1; // ������� S4
	UINT      nS4L1_1; // ���������� �������� S4
	UINT      dSw; // ������� ���������� ��������  � ��������� Z
	UINT      nSw; // ���������� �������� ���������� ��������  � ��������� Z
	double    StepSw; // ��� ���������� �������� � ��������� Z
	UINT      dSw2;  // ������� ���������� �������� � ��������� Y
	UINT      nSw2; // ��� ���������� �������� � ��������� Y
	double    StepSw2;// ��� ���������� �������� � ��������� Y

	// from reserved
	BYTE      IsS1L2; // S1 ����� ��� ����
	BYTE      IsS2L2; // S2 ����� ��� ����
	double    DeltaS1; // ���������� ����� ������ S1 (IsS1L2==TRUE)
	double    DeltaS2; // ���������� ����� ������ S2 (IsS2L2==TRUE)
	UINT      dS1L2; // ������� S1 ������� ���� (IsS1L2==TRUE)
	UINT      nS1L2; // ���������� �������� S1 ������� ���� (IsS1L2==TRUE)
	UINT      dS2L2; // ������� S2 ������� ���� (IsS2L2==TRUE)
	UINT      nS2L2; // ���������� �������� S2 ������� ���� (IsS2L2==TRUE)

	char    reserved[sizeof(double)*14-sizeof(BYTE)*2-sizeof(UINT)*4];
};

struct ApiArmRod {
	LPSTR           Text;
	UINT            Quantity;
	UINT *          List;
	UINT            QuantityArmRod;
	ApiArmElemRod * ArmRod;
};

struct ApiArmElemPlate
{
	UINT	dS1;		// ������� ���������� �������� S1
	double	StepS1;		// ��� ���������� �������� S1
	UINT	dS2;		// ������� ���������� �������� S2
	double	StepS2;		// ��� ���������� �������� S2
	UINT	dS3;		// ������� ���������� �������� S3
	double	StepS3;		// ��� ���������� �������� S3
	UINT	dS4;		// ������� ���������� �������� S4
	double	StepS4;		// ��� ���������� �������� S4
	UINT	dW;			// ������� ���������� ��������
	double	StepWx;		// ��� ���������� �������� �� ��� X
	double	StepWy;		// ��� ���������� �������� �� ��� Y
	BOOL	NoUp;		// ������� �������� ���
	BOOL	NoDown;		// ������ �������� ���
	BOOL	NoTrans;	// ���������� �������� ���
	char reserved[sizeof(double)*16];
};

struct ApiArmPlate {
	LPSTR             Text;
	UINT              Quantity;
	UINT *            List;
	ApiArmElemPlate   ArmPlate;
};

#pragma pack(pop)

#endif
