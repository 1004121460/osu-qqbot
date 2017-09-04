#include <stdio.h>
#include<math.h>
#include "demo.h"


void wtmsb(double pp,int pc,int tth,double bp1,double bp5,double acc1,double acc2,double acc3) {
	double A1 = 0;
	double A2 = 0;
	double A31 = 0;
	double A3 = 0;
	double A4 = 0;
	double total = 0;
	if (pp*pc*tth*bp1*bp5*acc1*acc2*acc3 == 0) {
		printf("������ݲ�����\n");
	}
	else{
		A1 = pp/(4*bp1-3*bp5);
		A2 = log(tth/pc)/log(15.5);
		if (pp < 1000) A31 = 1000*pc/(1.2*pp)-400;
		else if (pp < 7000) A31 = 1000*pc/(0.0008*pp*pp+0.4*pp)-400;
		else A31 = 1000*pc/(6*pp)-400;
		if (A31 > 1) A3 = log(A31)/log(24.5);
		else A3 = 0;
		A4 = pow((acc1+acc2+acc3)/3,5);
		total = A1*A2*A3*A4;
		printf("BPָ��:%.2f �ο�ֵ12.00\n",A1);
		printf("TTHָ��:%.2f �ο�ֵ2.00\n",A2);
		printf("PCָ��:%.2f �ο�ֵ2.00\n",A3);
		printf("ACCָ��:%.4f �ο�ֵ0.9000\n",A4);
		printf("�ۺ�ָ��:%.2f\n",total);
		if (pp < 300) printf("�ú�pp�ϵͣ�����������\n");
		else if (total >= 55) printf("�úųɼ�׿Խ��ͬ�ֶ��е�����!\n");
		else if (total >= 44) printf("�úųɼ����㣬��׼���������!\n");
		else if (A3 < 1 || A1 < 3) printf("����:�����϶���С�Ż������ߵ�!\n");
		else if (A3 < 1.7) {
			if (A1 < 9) printf("����:Ҫô�츳��Ⱥ��ҪôС�Ż������ߵ�,��֮���pp�������!\n");
			else{
				if (A4 < 0.75) printf("����:��Ȼ�츳��Ⱥ,����������ͼ��!\n");
				else if (A4 < 0.88) printf("����:��Ȼ�츳��Ⱥ�����ǽ��黨Щpc�ú���ϰһ��acc��!\n");
				else if (A2 < 1.7) printf("����:��һ�����츳�ĳ���ppˢ��,�����㲻Ҫre��!\n");
				else if (A2 < 1.9) printf("����:��һ�����츳�ĸ߼�ppˢ��,���齵��reͼ����!\n");
				else printf("����:��һ�����츳�������ppˢ��,��������ۺ�ͼ!\n");
			}
		}
		else if (A3 < 1.9) {
			if (A1 < 9 && A4 > 0.75) printf("����:��һ���츳������һ��ʱ���ڻ��ǿ��Է���һ����!\n");
			if (A1 < 11 && A4 > 0.75) printf("����:��һ���츳������һ��ʱ���ڻ��ǿ���С����һ���!\n");
			else{
				if (A4 < 0.75) printf("����:��Ȼ��һЩ�츳,����������ͼ��!\n");
				else if (A4 < 0.88) printf("����:��Ȼ��һЩ�츳�����ǽ��黨Щpc�ú���ϰһ��acc��!\n");
				else if (A2 < 1.7) printf("����:��һ����׼ppˢ��,�����㲻Ҫre��!\n");
				else if (A2 < 1.9) printf("����:��һ����׼ppˢ��,���齵��reͼ����!\n");
				else if (A2 < 2.1) printf("����:��һ����׼ppˢ��,��������ۺ�ͼ!\n");
				else printf("����:��������ȽϺ�������Ӧ�ú͸������͵��˶���һ��!\n");
			}
		}
		else if (A3 < 2.1) {
			if (A1 < 9 && A4 > 0.75) printf("����:���������ɹ�ƿ�����ˣ�����һ��ʱ���ڻ��ǿ��Է���һ����!\n");
			if (A1 < 11 && A4 > 0.75) printf("����:Ҫô�����ɹ�ƿ���ڣ�Ҫô֮ǰ��̫�켴������ƿ����!\n");
			else{
				if (A4 < 0.75) printf("����:��ɶ������,����������ͼ��!\n");
				else if (A4 < 0.88) printf("����:�Ƚ����������ǽ���ú���ϰһ��acc��!\n");
				else if (A2 < 1.7) printf("����:��һ��û�츳��ppˢ��,�����㲻Ҫre��!\n");
				else if (A2 < 1.9) printf("����:��һ��û�츳��ppˢ��,���齵��reͼ����!\n");
				else printf("����:�Ƚ����������ǿ���ĳЩ��������Ƿȱ����ο�ָ��!\n");
			}
		}
		else if (A3 < 2.4) {
			if (A1 < 9 && A4 > 0.75) printf("����:�����Լ��������ڷ���!\n");
			if (A1 < 11 && A4 > 0.75) printf("����:Ҳ����ƿ���ڸ����������������ܿ˷���!\n");
			else{
				if (A4 < 0.75) printf("����:����ĺ�ǿ,����������ͼ��!\n");
				else if (A4 < 0.88) printf("����:����ĺ�ǿ�����ǽ���ú���ϰһ��acc��!\n");
				else if (A2 < 1.7) printf("����:��һ��û���˵�ppˢ��,�����㲻Ҫre��!\n");
				else if (A2 < 1.9) printf("����:��һ��û���˵�ppˢ��,���齵��reͼ����!\n");
				else printf("����:�⺢��ƿ����!\n");
			}
		}
		else {
			if (A1 < 10 && A4 > 0.75) printf("����:��ͼ������㣬������û����!\n");
			else{
				if (A2 < 1.8) printf("����:����ô��reͼ�����ô����úÿ����°�!\n");
				else printf("����:�㲻�ʺ���ʺ��ɾ��Ϸ��!\n");
			}
		}
	}
}




