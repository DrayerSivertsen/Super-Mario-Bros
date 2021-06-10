#include "PhysicalProperties.h"

//1600 X 900
//block = 60

//first row (y) = 540
//second higher row(y) = 300?


//Physical Props section
PhysicalProps::PhysicalProps()
{
	//ground
	this->ground1.setFillColor(sf::Color::Transparent);
	this->ground1.setSize(sf::Vector2f(4140, 120));
	this->ground1.setPosition(sf::Vector2f(0, 782));
	//ground2
	this->ground2.setFillColor(sf::Color::Transparent);
	this->ground2.setSize(sf::Vector2f(900, 120));
	this->ground2.setPosition(sf::Vector2f(ground2X, 782));
	//ground3
	this->ground3.setFillColor(sf::Color::Transparent);
	this->ground3.setSize(sf::Vector2f(3840, 120));
	this->ground3.setPosition(sf::Vector2f(ground3X, 782));
	//ground4
	this->ground4.setFillColor(sf::Color::Transparent);
	this->ground4.setSize(sf::Vector2f(3360, 120));
	this->ground4.setPosition(sf::Vector2f(ground4X, 782));

	//tube1 //g1
	this->tube1.setFillColor(sf::Color::Transparent);
	this->tube1.setSize(sf::Vector2f(100, 120));
	this->tube1.setPosition(sf::Vector2f(1690, 662));
	//tube2
	this->tube2.setFillColor(sf::Color::Transparent);
	this->tube2.setSize(sf::Vector2f(100, 180));
	this->tube2.setPosition(sf::Vector2f(2290, 602));
	//tube3
	this->tube3.setFillColor(sf::Color::Transparent);
	this->tube3.setSize(sf::Vector2f(100, 240));
	this->tube3.setPosition(sf::Vector2f(2770, 542));
	//tube4
	this->tube4.setFillColor(sf::Color::Transparent);
	this->tube4.setSize(sf::Vector2f(100, 240));
	this->tube4.setPosition(sf::Vector2f(3430, 542));
	//tube5 //g4
	this->tube5.setFillColor(sf::Color::Transparent);
	this->tube5.setSize(sf::Vector2f(100, 120));
	this->tube5.setPosition(sf::Vector2f(ground4X + 60 * 8.19, 662));
	//tube6
	this->tube6.setFillColor(sf::Color::Transparent);
	this->tube6.setSize(sf::Vector2f(100, 120));
	this->tube6.setPosition(sf::Vector2f(ground4X + 60 * 24.19, 662));

	//3 + last chunk r2 * 60
	//sb1 //first chunk //g3
	this->sb1.setFillColor(sf::Color::Transparent);
	this->sb1.setSize(sf::Vector2f(60, 60));
	this->sb1.setPosition(sf::Vector2f(ground3X + 60 * 45, 722));
	//sb2
	this->sb2.setFillColor(sf::Color::Transparent);
	this->sb2.setSize(sf::Vector2f(60, 60 * 2));
	this->sb2.setPosition(sf::Vector2f(ground3X + 60 * 46, 722 - 60));
	//sb3
	this->sb3.setFillColor(sf::Color::Transparent);
	this->sb3.setSize(sf::Vector2f(60, 60 * 3));
	this->sb3.setPosition(sf::Vector2f(ground3X + 60 * 47, 722 - 60 * 2));
	//sb4 //long boi
	this->sb4.setFillColor(sf::Color::Transparent);
	this->sb4.setSize(sf::Vector2f(60, 60 * 4));
	this->sb4.setPosition(sf::Vector2f(ground3X + 60 * 48, 722 - 60 * 3));
	//sb5 //second chunk //g3 //long boi
	this->sb5.setFillColor(sf::Color::Transparent);
	this->sb5.setSize(sf::Vector2f(60, 60 * 4));
	this->sb5.setPosition(sf::Vector2f(ground3X + 60 * 51, 722 - 60 * 3));
	//sb6
	this->sb6.setFillColor(sf::Color::Transparent);
	this->sb6.setSize(sf::Vector2f(60, 60 * 3));
	this->sb6.setPosition(sf::Vector2f(ground3X + 60 * 52, 722 - 60 * 2));
	//sb7
	this->sb7.setFillColor(sf::Color::Transparent);
	this->sb7.setSize(sf::Vector2f(60, 60 * 2));
	this->sb7.setPosition(sf::Vector2f(ground3X + 60 * 53, 722 - 60));
	//sb8
	this->sb8.setFillColor(sf::Color::Transparent);
	this->sb8.setSize(sf::Vector2f(60, 60));
	this->sb8.setPosition(sf::Vector2f(ground3X + 60 * 54, 722));
	//sb9 //third chunk //g3
	this->sb9.setFillColor(sf::Color::Transparent);
	this->sb9.setSize(sf::Vector2f(60, 60));
	this->sb9.setPosition(sf::Vector2f(ground3X + 60 * 59, 722));
	//sb10
	this->sb10.setFillColor(sf::Color::Transparent);
	this->sb10.setSize(sf::Vector2f(60, 60 * 2));
	this->sb10.setPosition(sf::Vector2f(ground3X + 60 * 60, 722 - 60));
	//sb11
	this->sb11.setFillColor(sf::Color::Transparent);
	this->sb11.setSize(sf::Vector2f(60, 60 * 3));
	this->sb11.setPosition(sf::Vector2f(ground3X + 60 * 61, 722 - 60 * 2));
	//sb12
	this->sb12.setFillColor(sf::Color::Transparent);
	this->sb12.setSize(sf::Vector2f(60, 60 * 4));
	this->sb12.setPosition(sf::Vector2f(ground3X + 60 * 62, 722 - 60 * 3));
	//sb13 //long boi
	this->sb13.setFillColor(sf::Color::Transparent);
	this->sb13.setSize(sf::Vector2f(60, 60 * 4));
	this->sb13.setPosition(sf::Vector2f(ground3X + 60 * 63, 722 - 60 * 3));
	//sb14 //fourth chunk //g4 //long boi
	this->sb14.setFillColor(sf::Color::Transparent);
	this->sb14.setSize(sf::Vector2f(60, 60 * 4));
	this->sb14.setPosition(sf::Vector2f(ground4X, 722 - 60 * 3));
	//sb15
	this->sb15.setFillColor(sf::Color::Transparent);
	this->sb15.setSize(sf::Vector2f(60, 60 * 3));
	this->sb15.setPosition(sf::Vector2f(ground4X + 60, 722 - 60 * 2));
	//sb16
	this->sb16.setFillColor(sf::Color::Transparent);
	this->sb16.setSize(sf::Vector2f(60, 60 * 2));
	this->sb16.setPosition(sf::Vector2f(ground4X + 60 * 2, 722 - 60));
	//sb17
	this->sb17.setFillColor(sf::Color::Transparent);
	this->sb17.setSize(sf::Vector2f(60, 60));
	this->sb17.setPosition(sf::Vector2f(ground4X + 60 * 3, 722));
	//sb18 //fith chunk //g4
	this->sb18.setFillColor(sf::Color::Transparent);
	this->sb18.setSize(sf::Vector2f(60, 60));
	this->sb18.setPosition(sf::Vector2f(ground4X + 60 * 26, 722));
	//sb19
	this->sb19.setFillColor(sf::Color::Transparent);
	this->sb19.setSize(sf::Vector2f(60, 60 * 2));
	this->sb19.setPosition(sf::Vector2f(ground4X + 60 * 27, 722 - 60));
	//sb20
	this->sb20.setFillColor(sf::Color::Transparent);
	this->sb20.setSize(sf::Vector2f(60, 60 * 3));
	this->sb20.setPosition(sf::Vector2f(ground4X + 60 * 28, 722 - 60 * 2));
	//sb21
	this->sb21.setFillColor(sf::Color::Transparent);
	this->sb21.setSize(sf::Vector2f(60, 60 * 4));
	this->sb21.setPosition(sf::Vector2f(ground4X + 60 * 29, 722 - 60 * 3));
	//sb22
	this->sb22.setFillColor(sf::Color::Transparent);
	this->sb22.setSize(sf::Vector2f(60, 60 * 5));
	this->sb22.setPosition(sf::Vector2f(ground4X + 60 * 30, 722 - 60 * 4));
	//sb23
	this->sb23.setFillColor(sf::Color::Transparent);
	this->sb23.setSize(sf::Vector2f(60, 60 * 6));
	this->sb23.setPosition(sf::Vector2f(ground4X + 60 * 31, 722 - 60 * 5));
	//sb24
	this->sb24.setFillColor(sf::Color::Transparent);
	this->sb24.setSize(sf::Vector2f(60, 60 * 7));
	this->sb24.setPosition(sf::Vector2f(ground4X + 60 * 32, 722 - 60 * 6));
	//sb25 //LAST BLOCKS
	this->sb25.setFillColor(sf::Color::Transparent);
	this->sb25.setSize(sf::Vector2f(60, 60 * 7));
	this->sb25.setPosition(sf::Vector2f(ground4X + 60 * 33, 722 - 60 * 6));
	//sb26 //long long boi
	this->sb26.setFillColor(sf::Color::Transparent);
	this->sb26.setSize(sf::Vector2f(60, 60 * 7));
	this->sb26.setPosition(sf::Vector2f(ground4X + 60 * 34, 722 - 60 * 6));

	//row 1
	//mb1 //first chunk
	this->mb1.setFillColor(sf::Color::Transparent);
	this->mb1.setSize(sf::Vector2f(60, 60));
	this->mb1.setPosition(sf::Vector2f(960, 540));
	//bb1 //second chunk
	this->bb1.setFillColor(sf::Color::Transparent);
	this->bb1.setSize(sf::Vector2f(60, 60));
	this->bb1.setPosition(sf::Vector2f(1200, 540));
	//mb2
	this->mb2.setFillColor(sf::Color::Transparent);
	this->mb2.setSize(sf::Vector2f(60, 60));
	this->mb2.setPosition(sf::Vector2f(1260, 540));
	//bb2
	this->bb2.setFillColor(sf::Color::Transparent);
	this->bb2.setSize(sf::Vector2f(60, 60));
	this->bb2.setPosition(sf::Vector2f(1320, 540));
	//mb3
	this->mb3.setFillColor(sf::Color::Transparent);
	this->mb3.setSize(sf::Vector2f(60, 60));
	this->mb3.setPosition(sf::Vector2f(1380, 540));
	//bb3
	this->bb3.setFillColor(sf::Color::Transparent);
	this->bb3.setSize(sf::Vector2f(60, 60));
	this->bb3.setPosition(sf::Vector2f(1440, 540));
	//bb4 //third chunk
	this->bb4.setFillColor(sf::Color::Transparent);
	this->bb4.setSize(sf::Vector2f(60, 60));
	this->bb4.setPosition(sf::Vector2f(ground2X + 60 * 6, 540));
	//mb4
	this->mb4.setFillColor(sf::Color::Transparent);
	this->mb4.setSize(sf::Vector2f(60, 60));
	this->mb4.setPosition(sf::Vector2f(ground2X + 60 * 7, 540));
	//bb5
	this->bb5.setFillColor(sf::Color::Transparent);
	this->bb5.setSize(sf::Vector2f(60, 60));
	this->bb5.setPosition(sf::Vector2f(ground2X + 60 * 8, 540));
	//bb6 //fourth chunk
	this->bb6.setFillColor(sf::Color::Transparent);
	this->bb6.setSize(sf::Vector2f(60, 60));
	this->bb6.setPosition(sf::Vector2f(ground3X + 60 * 5, 540));
	//bb7 //fith chunk
	this->bb7.setFillColor(sf::Color::Transparent);
	this->bb7.setSize(sf::Vector2f(60, 60));
	this->bb7.setPosition(sf::Vector2f(ground3X + 60 * 11, 540));
	//bb8
	this->bb8.setFillColor(sf::Color::Transparent);
	this->bb8.setSize(sf::Vector2f(60, 60));
	this->bb8.setPosition(sf::Vector2f(ground3X + 60 * 12, 540));
	//mb5 //sixth chunk
	this->mb5.setFillColor(sf::Color::Transparent);
	this->mb5.setSize(sf::Vector2f(60, 60));
	this->mb5.setPosition(sf::Vector2f(ground3X + 60 * 17, 540));
	//mb6 //seventh chunk
	this->mb6.setFillColor(sf::Color::Transparent);
	this->mb6.setSize(sf::Vector2f(60, 60));
	this->mb6.setPosition(sf::Vector2f(ground3X + 60 * 20, 540));
	//mb7 //eighth chunk
	this->mb7.setFillColor(sf::Color::Transparent);
	this->mb7.setSize(sf::Vector2f(60, 60));
	this->mb7.setPosition(sf::Vector2f(ground3X + 60 * 23, 540));
	//bb9 //ninth chunk
	this->bb9.setFillColor(sf::Color::Transparent);
	this->bb9.setSize(sf::Vector2f(60, 60));
	this->bb9.setPosition(sf::Vector2f(ground3X + 60 * 29, 540));
	//bb10 //tenth chunk
	this->bb10.setFillColor(sf::Color::Transparent);
	this->bb10.setSize(sf::Vector2f(60, 60));
	this->bb10.setPosition(sf::Vector2f(ground3X + 60 * 40, 540));
	//bb11
	this->bb11.setFillColor(sf::Color::Transparent);
	this->bb11.setSize(sf::Vector2f(60, 60));
	this->bb11.setPosition(sf::Vector2f(ground3X + 60 * 41, 540));
	//bb12 //eleventh chunk
	this->bb12.setFillColor(sf::Color::Transparent);
	this->bb12.setSize(sf::Vector2f(60, 60));
	this->bb12.setPosition(sf::Vector2f(ground4X + 60 * 13, 540));
	//bb13 
	this->bb13.setFillColor(sf::Color::Transparent);
	this->bb13.setSize(sf::Vector2f(60, 60));
	this->bb13.setPosition(sf::Vector2f(ground4X + 60 * 14, 540));
	//mb8
	this->mb8.setFillColor(sf::Color::Transparent);
	this->mb8.setSize(sf::Vector2f(60, 60));
	this->mb8.setPosition(sf::Vector2f(ground4X + 60 * 15, 540));
	//bb14
	this->bb14.setFillColor(sf::Color::Transparent);
	this->bb14.setSize(sf::Vector2f(60, 60));
	this->bb14.setPosition(sf::Vector2f(ground4X + 60 * 16, 540));

	//row2
	//mb9 //1st chunk
	this->mb9.setFillColor(sf::Color::Transparent);
	this->mb9.setSize(sf::Vector2f(60, 60));
	this->mb9.setPosition(sf::Vector2f(1320, 300));
	//bb15 //2nd chunk
	this->bb15.setFillColor(sf::Color::Transparent);
	this->bb15.setSize(sf::Vector2f(60, 60));
	this->bb15.setPosition(sf::Vector2f(ground2X + 60 * 9, 300));
	//bb16
	this->bb16.setFillColor(sf::Color::Transparent);
	this->bb16.setSize(sf::Vector2f(60, 60));
	this->bb16.setPosition(sf::Vector2f(ground2X + 60 * 10, 300));
	//bb17
	this->bb17.setFillColor(sf::Color::Transparent);
	this->bb17.setSize(sf::Vector2f(60, 60));
	this->bb17.setPosition(sf::Vector2f(ground2X + 60 * 11, 300));
	//bb18
	this->bb18.setFillColor(sf::Color::Transparent);
	this->bb18.setSize(sf::Vector2f(60, 60));
	this->bb18.setPosition(sf::Vector2f(ground2X + 60 * 12, 300));
	//bb19
	this->bb19.setFillColor(sf::Color::Transparent);
	this->bb19.setSize(sf::Vector2f(60, 60));
	this->bb19.setPosition(sf::Vector2f(ground2X + 60 * 13, 300));
	//bb20
	this->bb20.setFillColor(sf::Color::Transparent);
	this->bb20.setSize(sf::Vector2f(60, 60));
	this->bb20.setPosition(sf::Vector2f(ground2X + 60 * 14, 300));
	//bb21
	this->bb21.setFillColor(sf::Color::Transparent);
	this->bb21.setSize(sf::Vector2f(60, 60));
	this->bb21.setPosition(sf::Vector2f(ground2X + 60 * 15, 300));
	//bb22
	this->bb22.setFillColor(sf::Color::Transparent);
	this->bb22.setSize(sf::Vector2f(60, 60));
	this->bb22.setPosition(sf::Vector2f(ground2X + 60 * 16, 300));
	//bb23 //3rd chunk
	this->bb23.setFillColor(sf::Color::Transparent);
	this->bb23.setSize(sf::Vector2f(60, 60));
	this->bb23.setPosition(sf::Vector2f(ground3X + 60 * 2, 300));
	//bb24
	this->bb24.setFillColor(sf::Color::Transparent);
	this->bb24.setSize(sf::Vector2f(60, 60));
	this->bb24.setPosition(sf::Vector2f(ground3X + 60 * 3, 300));
	//bb25
	this->bb25.setFillColor(sf::Color::Transparent);
	this->bb25.setSize(sf::Vector2f(60, 60));
	this->bb25.setPosition(sf::Vector2f(ground3X + 60 * 4, 300));
	//mb10
	this->mb10.setFillColor(sf::Color::Transparent);
	this->mb10.setSize(sf::Vector2f(60, 60));
	this->mb10.setPosition(sf::Vector2f(ground3X + 60 * 5, 300));
	//mb11 //4th chunk
	this->mb11.setFillColor(sf::Color::Transparent);
	this->mb11.setSize(sf::Vector2f(60, 60));
	this->mb11.setPosition(sf::Vector2f(ground3X + 60 * 20, 300));
	//bb26 //5th chunk
	this->bb26.setFillColor(sf::Color::Transparent);
	this->bb26.setSize(sf::Vector2f(60, 60));
	this->bb26.setPosition(sf::Vector2f(ground3X + 60 * 32, 300));
	//bb27
	this->bb27.setFillColor(sf::Color::Transparent);
	this->bb27.setSize(sf::Vector2f(60, 60));
	this->bb27.setPosition(sf::Vector2f(ground3X + 60 * 33, 300));
	//bb28
	this->bb28.setFillColor(sf::Color::Transparent);
	this->bb28.setSize(sf::Vector2f(60, 60));
	this->bb28.setPosition(sf::Vector2f(ground3X + 60 * 34, 300));
	//bb29 //6th chunk
	this->bb29.setFillColor(sf::Color::Transparent);
	this->bb29.setSize(sf::Vector2f(60, 60));
	this->bb29.setPosition(sf::Vector2f(ground3X + 60 * 39, 300));
	//mb12
	this->mb12.setFillColor(sf::Color::Transparent);
	this->mb12.setSize(sf::Vector2f(60, 60));
	this->mb12.setPosition(sf::Vector2f(ground3X + 60 * 40, 300));
	//mb13
	this->mb13.setFillColor(sf::Color::Transparent);
	this->mb13.setSize(sf::Vector2f(60, 60));
	this->mb13.setPosition(sf::Vector2f(ground3X + 60 * 41, 300));
	//bb30
	this->bb30.setFillColor(sf::Color::Transparent);
	this->bb30.setSize(sf::Vector2f(60, 60));
	this->bb30.setPosition(sf::Vector2f(ground3X + 60 * 42, 300));


	//FLAG
	this->flagHitbox.setFillColor(sf::Color::Transparent);
	this->flagHitbox.setSize(sf::Vector2f(60, -60 * 11));
	this->flagHitbox.setPosition(sf::Vector2f(9300 + 60 * 43, 782));
}

void PhysicalProps::render(sf::RenderTarget& target)
{
	target.draw(this->ground1);
	target.draw(this->ground2);
	target.draw(this->ground3);
	target.draw(this->ground4);

	target.draw(this->tube1);
	target.draw(this->tube2);
	target.draw(this->tube3);
	target.draw(this->tube4);
	target.draw(this->tube5);
	target.draw(this->tube6);

	target.draw(this->sb1);
	target.draw(this->sb2);
	target.draw(this->sb3);
	target.draw(this->sb4);
	target.draw(this->sb5);
	target.draw(this->sb6);
	target.draw(this->sb7);
	target.draw(this->sb8);
	target.draw(this->sb9);
	target.draw(this->sb10);
	target.draw(this->sb11);
	target.draw(this->sb12);
	target.draw(this->sb13);
	target.draw(this->sb14);
	target.draw(this->sb15);
	target.draw(this->sb16);
	target.draw(this->sb17);
	target.draw(this->sb18);
	target.draw(this->sb19);
	target.draw(this->sb20);
	target.draw(this->sb21);
	target.draw(this->sb22);
	target.draw(this->sb23);
	target.draw(this->sb24);
	target.draw(this->sb25);
	target.draw(this->sb26);
	target.draw(this->sb27);

	//row1
	target.draw(this->mb1);
	target.draw(this->mb2);
	target.draw(this->mb3);
	target.draw(this->mb4);
	target.draw(this->mb5);
	target.draw(this->mb6);
	target.draw(this->mb7);
	target.draw(this->mb8);

	target.draw(this->bb1);
	target.draw(this->bb2);
	target.draw(this->bb3);
	target.draw(this->bb4);
	target.draw(this->bb5);
	target.draw(this->bb6);
	target.draw(this->bb7);
	target.draw(this->bb8);
	target.draw(this->bb9);
	target.draw(this->bb10);
	target.draw(this->bb11);
	target.draw(this->bb12);
	target.draw(this->bb13);
	//

	//row2
	target.draw(this->mb9);
	target.draw(this->mb10);
	target.draw(this->mb11);
	target.draw(this->mb12);
	target.draw(this->mb13);


	target.draw(this->bb14);
	target.draw(this->bb15);
	target.draw(this->bb16);
	target.draw(this->bb17);
	target.draw(this->bb18);
	target.draw(this->bb19);
	target.draw(this->bb20);
	target.draw(this->bb21);
	target.draw(this->bb22);
	target.draw(this->bb23);
	target.draw(this->bb24);
	target.draw(this->bb25);
	target.draw(this->bb26);
	target.draw(this->bb27);
	target.draw(this->bb28);
	target.draw(this->bb29);
	target.draw(this->bb30);

	//target.draw(this->bb30);
	//

	target.draw(this->flagHitbox);
}
