#include "nutility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static int icmp(const void *vp1, const void *vp2)
{
	return *(const int *)vp1 - *(const int *)vp2;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void sleep(double sec)
{
	clock_t start = clock();

	while ((double)(clcok() - start) / CLOCKS_PER_SEC < sec)
		;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int isprime(int val)
{
	if (val == 0 || val == 1)
		return 0;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return 0;

	return 1;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val) {
		++digit_count;
		val /= 10;
	}

	return digit_count;
}



//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------



void pline(void)
{
	printf("\n-------------------------------------------------------------------------------\n");
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void randomize(void)
{
	srand((unsigned)time(0));
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void set_random_array(int *p, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		p[i] = rand() % 1000;
	}
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void set_random_array2(int *p, size_t size, int low, int high)
{
	for (size_t i = 0; i < size; ++i) {
		p[i] = rand() % (high - low + 1) + low;
	}
}


//void display_array(const int *p, size_t size)
//{
//	for (size_t i = 0; i < size; ++i) {
//		if (i && i % 20 == 0)
//			printf("\n");
//		printf("%3d ", p[i]);
//	}
//	pline();
//
//}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void sort(int *p, size_t size)
{
	qsort(p, size, sizeof(*p), icmp);
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void sgets(char *p)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF) {
		*p++ = (char)c;
	}
	*p = '\0';
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------



void sgets_s(char *p, int size)
{
	int c;
	int len = 0;

	while ((c = getchar()) != '\n') {
		if (len == size - 1)
			break;
		++len;
		*p++ = (char)c;
	}
	*p = '\0';
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


void display_array(const int *p, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		if (i && i % 20 == 0)
			printf("\n");
		printf("%3d ", p[i]);
	}
	printf("\n----------------------------------------------------------------------\n");

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void gswap(void *vp1, void *vp2, size_t n)
{
	char *p1 = (char *)vp1;
	char *p2 = (char *)vp2;

	while (n--) {
		char temp = *p1;
		*p1++ = *p2;
		*p2++ = temp;
	}
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


const char * random_name()
{
	static const char *const pnames[] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahide",
		"nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
		"izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
		"belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur",
		"aynur", "yasin", "polat", "naz", "yusuf", "gulsen", "nazif", "demir", "egemen", "necmi",
		"fazilet", "celal", "ismail", "kamile", "mahir", "caner", "suleyman", "cezmi", "diana", "sadullah",
		"atif", "huseyin", "necmettin", "devlet", "sezen", "hulya", "necmiye", "ece", "julide", "onat",
		"emre", "sinem", "teoman", "irmak", "cihat", "adem", "bilgin", "muzaffer", "suphi", "pelin",
		"yalcin", "kenan", "atalay", "akin", "durmus", "haluk", "kelami", "alparslan", "busra", "kasim",
		"durriye", "tarcan", "nihal", "gizem", "bilge", "dilek", "yasemin", "fahri", "furkan", "papatya",
		"hakki", "fadime", "devrim", "abdi", "tayyip", "yurdakul", "zekai", "nagehan", "ata", "naci",
		"mert", "yelda", "cebrail", "rumeysa", "beyhan", "azize", "cemil", "sezer", "beste", "ciler",
		"enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil", "muruvvet",
		"nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju", "sadettin",
		"su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla", "hilal",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen", "pinat",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", };

	return pnames[rand() % asize(pnames)];
	
}
//--------------------------------------------------
//--------------------------------------------------
const char *random_surname()
{
	static const char* const pfnames[] = {
"uyar", "poturgeli", "fincan", "tercan", "pakdamar", "onaran", "avci", "lokmaci", "yanardoner", "portakal",
"fitrat", "kalemsiz", "etci", "degirmenci", "renacan", "yavas", "ortaca", "beyaz", "oztoklu", "aylak",
"sucu", "kapici", "yelden", "serinsun", "kotek", "nurtopu", "dingin", "uraz", "koylu", "safkan",
"bahceli", "zengin", "yeldirmen", "soylu", "hurmaci", "alemdar", "karaorman", "fakir", "candamar", "celik",
"gumus", "agaoglu", "komurcu", "kalpsiz", "kara", "dokuzcan", "comakci", "adiguzel", "kilicdar", "ecevit",
"karaduman", "yaradan", "tekinalp", "erim", "yildirim", "temizkalp", "yasmak", "akkay", "bilgic", "zaimoglu",
"emirkulu", "cuhadar", "kayabasi", "tertemiz", "merdane", "gurkas", "topkapi", "altinorak", "unalmis", "karakis",
"demirdogen", "sonuzun", "uluocak", "yeldirme", "sonmez", "bakirci", "ovacik", "yasli", "damar", "bayraktar",
"yurtsuz", "saricakir", "koralp", "edepsiz", "kelepce", "mazgirt", "muglali", "geldik", "simsek", "supuren",
"karayel", "maganda", "tufancan", "yosun", "bekar", "ademoglu", "pirlanta", "konca", "oltu", "kirci",
"kosnuk", "ersoy", "kulaksiz", "kalinkas", "tamirci", "altinisik", "sarikafa", "ozvezneci", "gilgamis", "yurdakul",
"efelik", "osmaneli", "boztas", "yilmaz", "yorganci", "reis", "resimci", "engerek", "derin", "acar",
"yilgin", "telek", "tilki", "temizel", "dokmeci", "orhancan", "azmak", "aslan", "uzunadam", "komcu",
"ordulu", "gedik", "tokatci", "kolcak", "esbereli", "kazanci", "samanci", "konak", "takes", "karakoyun",
"kalpten", "tuztas", "baturalp", "harmanci", "tuzcu", "akarsu", "cankoc", "yasayavas", "yersiz", "yangin",
"semiz", "altindag", "hepguler", "terlemez", "celiker", "karaelmas", "girit", "cangoz", "zalim", "yanardag",
"korukcu", "erdogan", "baklavaci", "kirboga", "silifkeli", "cevikkol", "engereke", "firatonu", "uslu", "cilingir",
"kusmen", "kahraman", "elebasi", "daglarca", "ormanci", "umutsuz", "arcan", "keskin", "tekkilic", "otaci",
"tepsici", "karabatur", "edepli", "bozkaya", "soysalan", "aklikit", "tamgun", "akkuyu", "unkapani", "canbay",
"kucukkaya", "serce", "tepecik", "dumbuk", "akyoldas", "merzifon", "cengaver", "kilinc", "yolyapan", "nazik",
"mirza", "salca", "gultekin", "yaygara", "acuka", "kapan", "kesman", "demirel", "tozkoporan", "olmez",
"tantana", "akyildiz", "karamuk", "eloglu", "yagizeli", "tunali", "kocyigit", "yorgun", "cansever", "sarpdemir",
"yikilmaz", "karakuzu", "iliksiz", "unalan", "sofuoglu", "girik", "ulakci", "temiz", "akgunes", "yavasakan",
"kaplan", "ergin", "elitemiz", "selercan", "elkizi", "polatkan", "sener", "uzay", "yurekli", "dosteli",
"akcalar", "gamsiz", "ongun", "kurban", "lalezar", "jilet", "sulugoz", "tarumar", "miskin", "sefiloglu",
"savaskan", "sivri", "topatan", "karasaban", "kurtulus", "mertek", "acgoze", "ertakan", "miskinoglu",
"fedai", "yurekyakan", "karataban", "saferikli", "malazgirt", "esteberli", "kilimci", "soyubozuk"
	};

	return pfnames[rand() % asize(pfnames)];
}
//--------------------------------------------------
//--------------------------------------------------
const char * random_town()
{
	static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "kocaeli", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "eskisehir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "burdur", "antalya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "edirne", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };
	return ptowns[rand() % asize(ptowns)];
}