﻿﻿CREATE DATABASE NDSV

CREATE TABLE PLAYER
(
	PlayerID int,
	Username nchar(15),
	TotalScore int,
	GameLife int,
	
	PRIMARY KEY(PlayerID)
)

CREATE TABLE SCENE
(
	SceneID int,
	SceneName nvarchar(30),

	PRIMARY KEY (SceneID)
)

CREATE TABLE QUESTION
(
	QuestionID int,
	Question nvarchar(4000),
	AnswerA nvarchar(4000),
	AnswerB nvarchar(4000),
	AnswerC nvarchar(4000),
	AnswerD nvarchar(4000),
	RightAnswer int,
	SceneID int,
	isBonus bit,

	PRIMARY KEY (QuestionID),
	CONSTRAINT FK_QUESTION_SCENE FOREIGN KEY(SceneID) REFERENCES SCENE(SceneID)
)

CREATE TABLE RESULT
(
	PlayerID int,
	SceneID int,
	Score int,
	isCompleted bit,

	CONSTRAINT FK_RESULT_PLAYER FOREIGN KEY(PlayerID) REFERENCES PLAYER(PlayerID),
	CONSTRAINT FK_RESULT_SCENE FOREIGN KEY(SceneID) REFERENCES SCENE(SceneID)
)

Go
---TRIGGER
--R1
CREATE TRIGGER R1 ON PLAYER
	FOR INSERT, UPDATE
AS
IF UPDATE(Username)
BEGIN
	IF(EXISTS(SELECT * FROM inserted WHERE LEN(Username) <= 0 OR LEN(Username) > 15))
	BEGIN
	RAISERROR (N'Lỗi: Tên đăng nhập người dùng không được vượt quá giới hạn',16,1)
	ROLLBACK
	END
END

Go
--R2
CREATE TRIGGER R2 ON PLAYER
	FOR INSERT, UPDATE
AS
IF UPDATE(PlayerID)
BEGIN
	IF(EXISTS(SELECT * FROM inserted WHERE PlayerID < 0))
	BEGIN
	RAISERROR (N'Lỗi: Mã của người chơi không được là số âm',16,1)
	ROLLBACK
	END
END

Go
--R3
CREATE TRIGGER R3 ON SCENE
	FOR INSERT, UPDATE
AS
IF UPDATE(SceneID)
BEGIN
	IF(EXISTS(SELECT * FROM inserted WHERE SceneID < 0))
	BEGIN
	RAISERROR (N'Lỗi: Mã của màn chơi không được là số âm',16,1)
	ROLLBACK
	END
END

Go
--R4
CREATE TRIGGER R4 ON QUESTION
	FOR INSERT, UPDATE
AS
IF UPDATE(QuestionID)
BEGIN
	IF(EXISTS(SELECT * FROM inserted WHERE QuestionID < 0))
	BEGIN
	RAISERROR (N'Lỗi: Mã của câu hỏi không được là số âm',16,1)
	ROLLBACK
	END
END

Go
--R5
CREATE TRIGGER R5 ON QUESTION
	FOR INSERT, UPDATE
AS
IF UPDATE(RightAnswer)
BEGIN
	IF(EXISTS(SELECT * FROM inserted I WHERE I.RightAnswer != 0 AND I.RightAnswer != 1 AND I.RightAnswer != 2 AND I.RightAnswer != 3))
	BEGIN
	RAISERROR (N'Lỗi: Đáp án phải là A, B, C, D',16,1)
	ROLLBACK
	END
END

Go
--R6
CREATE TRIGGER R6 ON PLAYER
	FOR INSERT, UPDATE
AS
IF UPDATE(Username)
BEGIN
	IF((SELECT COUNT(P.PlayerID) FROM inserted I, PLAYER P WHERE I.Username = P.Username) > 1)
	BEGIN
	RAISERROR (N'Lỗi: Tên người dùng không được trùng',16,1)
	ROLLBACK
	END
END


--INSERT SCENE
INSERT INTO SCENE VALUES(0, N'Hai bà trưng');
INSERT INTO SCENE VALUES(1, N'Lý Thường Kiệt');
INSERT INTO SCENE VALUES(2, N'Trần Hưng Đạo');
INSERT INTO SCENE VALUES(3, N'Quang Trung');
INSERT INTO SCENE VALUES(4, N'Hồ Chí Minh');

--INSERT QUESTION

--Hai Ba Trung
INSERT INTO QUESTION VALUES(0, N'Hai Bà Trưng phất cờ khởi nghĩa năm nào?', N'Mùa xuân năm 40 TCN', N'Mùa xuân năm 40', N'981', N'938', 1, 0, 0);
INSERT INTO QUESTION VALUES(1, N'Khởi nghĩa Hai Bà Trưng tồn tại thời gian nào?', N'10 năm (43-53)', N'3 năm (40-43)', N'5 năm (40-45)', N'2 năm (40-42)', 1, 0, 0);
INSERT INTO QUESTION VALUES(2, N'Hai Bà Trưng khởi nghĩa nhằm mục đích', N'Trả thù cho Thi Sách', N'Trả thù nhà, đền nợ nước', N'Rửa hận', N'Trả thù riêng', 1, 0, 0);
INSERT INTO QUESTION VALUES(3, N'Nghĩa quân Hai Bà Trưng toàn thắng sau khi', N'Làm chủ tình hình', N'Giết Tô Định', N'Tô Định bỏ trốn', N'Làm chủ Mê Linh, đánh chiếm Cổ Loa, Tuy Lâu', 3, 0, 0);
INSERT INTO QUESTION VALUES(4, N'Sau khi cuộc khởi nghĩa thắng lợi, Hai Bà Trưng đã làm gì?', N'Xưng Vương', N'Xưng Vua', N'Xưng Đế', N'Chưa kịp tôn xưng', 0, 0, 0);
INSERT INTO QUESTION VALUES(5, N'Dưới thời Hai Bà Trưng, kinh đô nước ta đặt ở đâu?', N'Phong Châu', N'Mê Linh', N'Cổ Loa', N'Đông Anh', 1, 0, 0);
INSERT INTO QUESTION VALUES(6, N'Các nhà sử học nhận định họ của Hai Bà Trưng là gì?', N'Họ Hùng', N'Họ Triệu', N'Không có họ', N'Cả 3 đáp án trên', 3, 0, 1);
INSERT INTO QUESTION VALUES(7, N'Chồng của Trưng Trắc là Thi Sách, vậy chồng của Trưng Nhị là ai?', N'Đỗ Năng Tế', N'Hùng Nguyên', N'Đông Chính', N'Trưng Nhị không có chồng', 1, 0, 1);
INSERT INTO QUESTION VALUES(8, N'Việc Trưng Trắc được tôn làm vua và chọn Mê Linh làm nơi đóng đô có ý nghĩa gì?', N'Khẳng định vai trò và vị trí của người phụ nữ trong lịch sử', N'Lòng tự tôn dân tộc', N'Phụ nữ nắm quyền', N'Một triều đại mới được hình thành', 0, 0, 1);
INSERT INTO QUESTION VALUES(9, N'Tương truyền, để bảo toàn khí tiết, Hai Bà Trưng đã nhảy xuống sông nào tự vẫn?', N'Sông Lô', N'Sông Đáy', N'Sông Hát', N'Sông Đuống', 2, 0, 1);
INSERT INTO QUESTION VALUES(10, N'Được tin Hai Bà Trưng khởi nghĩa giành độc lập. Vua Hán đã', N'A.	Nhanh chóng liên kết với các nước xung quanh, tiếp tục tấn công nước ta', N'Xin giải hoà', N'Thắt cổ tự tử', N'Tức giận, đem quân sang đàn áp khởi nghĩa', 0, 0, 0);
INSERT INTO QUESTION VALUES(11, N'Cuộc khởi nghĩa Hai Bà Trưng bùng nổ tại', N'Mê Linh (Vĩnh Phúc)', N'Cổ Loa (Đông Anh – Hà Nội)', N'Hát Môn (Phúc Thọ – Hà Nội)', N'Luy Lâu (Thuận Thành – Bắc Ninh)', 2, 0, 0);
INSERT INTO QUESTION VALUES(12, N'Điểm độc đáo của cuộc khởi nghĩa Hai Bà Trưng là', N'Được đông đảo nhân dân tham gia', N'Có sự liên kết với các tù trưởng dân tộc thiểu số', N'Nhiều nữ tướng tham gia chỉ huy cuộc khởi nghĩa', N'Lực lượng nghĩa quân được tổ chức thành nhiều bộ phận; quân thủy, quân bộ và tượng binh', 2, 0, 0);
INSERT INTO QUESTION VALUES(13, N'Cuộc khởi nghĩa Hai Bà Trưng có ý nghĩa ra sao trong lịch sử dân tộc', N'Thể hiện khí phách anh hùng của dân tộc', N'Thể hiện khí phách dân tộc và vai trò to lớn của phụ nữ Việt Nam', N'Đánh bị ý chí xâm lược của nhà Hán', N'Mở ra thời đại mới trong lịch sử dân tộc', 1, 0, 0);
INSERT INTO QUESTION VALUES(14, N'Nguyên nhân nào dẫn tới cuộc khởi nghĩa của Hai Bà Trưng?', N'Oán hận trước ách đô hộ của nhà Hán', N'Chồng bà Trưng Trắc (Thi sách) bị Tô Địch giết hại', N'Chứng tỏ cho nhân dân biết, phụ nữ cũng đánh được giặc', N'Đáp án khác', 0, 0, 0);
INSERT INTO QUESTION VALUES(15, N'Cuộc khởi nghĩa Hai Bà Trưng năm 40 đã diễn ra như thế nào?', N'Từ Hát Môn, quân khởi nghĩa chiếm Mê Linh; Trưng Trắc lên ngôi vua đóng đô tại đây', N'Từ Mê Linh, quân khởi nghĩa tiến đánh Luy Lâu – trị sở của chính quyền đô hộ; Thái thú Tô Định bị giết tại trận', N'Được nhân dân nhiệt tình ảnh hưởng, quân khởi nghĩa nhanh chóng chiếm Cổ Loa, đập tan tận gốc rễ chính quyền đô hộ', N'Từ Hát Môn, quân khởi nghĩa chiếm Mê Linh, rồi Cổ Loa và Luy Lâu – trị sở của chính quyền đô hộ; Thái thú Tô Định phải trốn chạy về nước', 3, 0, 0);
INSERT INTO QUESTION VALUES(16, N'Chính quyền được thành lập sau khởi nghĩa Hai Bà Trung thắng lợi được đánh giá là', N'Chính quyền tuy còn sơ khai nhưng mang tính độc lập, tự chủ rõ ràng', N'Chính quyền do nhân dân bầu ra', N'Chính quyền được sự thừa nhận của phong kiến phương Bắc', N'Chính quyền chủ yếu thực hiện chức năng quân sự', 0, 0, 1);
INSERT INTO QUESTION VALUES(17, N'Điểm giống nhau giữa khởi nghĩa Hai Bà Trưng và khởi nghĩa Lý Bí là gì?', N'Diễn ra qua hai giai đoạn: khởi nghĩa và kháng chiến', N'Chống ách đô hộ của nhà Hán', N'Chống ách đô hộ của nhà Đường', N'Khởi nghĩa thắng lợi, mở ra giai đoạn mới trong lịch sử dân tộc', 0, 0, 1);
INSERT INTO QUESTION VALUES(18, N'Bộ sử cổ nhất nào đề cập đến Khởi nghĩa Hai Bà Trưng', N'Đại Việt Sử kí toàn Thư', N'Đại Việt Sử Lược', N'Hậu Hán Thư', N'Thiên Nam Ngữ Lục', 1, 0, 1);
INSERT INTO QUESTION VALUES(19, N'Khởi nghĩa Hai Bà Trưng giành được bao nhiêu tỉnh thành', N'53', N'54', N'55', N'56', 3, 0, 1);
-- Ly Thuong Kiet
INSERT INTO QUESTION VALUES(20, N'Lý Thường Kiệt là hậu duệ của vị vua nổi tiếng nào?', N'Ngô Quyền', N'Lê Hoàn', N'Lý Công Uẩn', N'Cả ba đáp án đều sai', 0, 1, 0);
INSERT INTO QUESTION VALUES(21, N'Trước khi trở thành quan thái úy của triều đình, Lý Thường Kiệt là?', N'Quan văn', N'Quan võ', N'Thái giám', N'Chưa từng làm quan trước đó', 2, 1, 0);
INSERT INTO QUESTION VALUES(22, N'Tinh thần chủ động đối phó với quân Tống của nhà Lý thể hiện rõ trong chủ trương', N'Vườn không nhà trống', N'Ngồi yên đợi giặc không bằng đem quân đánh trước để chặn mũi nhọn của giặc', N'Lập phòng tuyến chắc chắn để chặn giặc', N'Tích cực chuẩn bị lương thảo, vũ khí, luyện quân để chống lại thế mạnh của giặc', 1, 1, 0);
INSERT INTO QUESTION VALUES(23, N'Khi biết quân Tống sang xâm lược, Lý Thường Kiệt làm gì?', N'Tấn công thành Ung Châu', N'Tấn công thành Liêm Châu, Khâm Châu', N'Dựng phòng tuyến Như Nguyệt', N'Cả A và B', 3, 1, 0);
INSERT INTO QUESTION VALUES(24, N'Lý Thường Kiệt đã đem quân vượt biên giới để phá tan sự chuẩn bị của quân Tống vào năm nào?', N'1070', N'1075', N'1076', N'1077', 1, 1, 0);
INSERT INTO QUESTION VALUES(25, N'Tướng nhà Tống nào chỉ huy lớn nhất của quân Tống xâm lược Đại Việt?', N'Quách Quỳ', N'Triệu Tiết', N'Lý Hiến', N'Dương Tiến Tùng', 0, 1, 0);
INSERT INTO QUESTION VALUES(26, N'Lý Thường Kiệt đã cho xây dựng chiến tuyến phòng thủ trên sông nào?', N'Sông Nhị Hà (sông Lô)', N'Sông Thương (sông Đào Hoa)', N'Sông Hồng', N'Sông Cầu', 3, 1, 0);
INSERT INTO QUESTION VALUES(27, N'Sau khi đánh bại quân Tống ở sông Như Nguyệt, Lý Thường Kiệt làm gì?', N'Chủ động giảng hòa', N'Truy kích địch đến biên giới', N'Tiêu diệt tàn quân', N'Rút quân về Thăng Long', 0, 1, 0);
INSERT INTO QUESTION VALUES(28, N'Bài thơ “Nam quốc sơn hà”ra đời trong hoàn cảnh nào?', N'Trong cuộc tập kích lên đất Tống của quân ta', N'Đang lúc diễn ra trận đánh ác liệt ở phòng tuyến sông Như Nguyệt', N'Khi vua Tống đầu hàng Đại Việt', N'Trong buổi lễ mừng chiến thắng quân Tống', 1, 1, 0);
INSERT INTO QUESTION VALUES(29, N'Bài thơ “Nam quốc sơn hà” vang lên trong đền thờ của ai?', N'Hai Bà Trưng', N'Bà Triệu', N'Ngô Quyền', N'Trương Hống và Trương Hát', 3, 1, 0);
INSERT INTO QUESTION VALUES(30, N'Từng chinh chiến nhiều nơi đem lại thắng lợi lớn cho nhà Lý nhưng tên tuổi của Lý Thường Kiệt gắn liền với cuộc kháng chiến chống quân nào nhất?', N'Chiêm Thành', N'Bắc Tống', N'Nguyên Mông', N'Nam Tống', 1, 1, 0);
INSERT INTO QUESTION VALUES(31, N'Lý Thường Kiệt đánh bại và bắt được vua nào của Chiêm Thành?', N'Chế Mân', N'Chế Củ', N'Chế Bồng Nga', N'Chế Ma Na', 1, 1, 0);
INSERT INTO QUESTION VALUES(32, N'Sau khi đánh bại quân Tống ở sông Như Nguyệt, Lý Thường Kiệt làm gì?', N'Chủ động giảng hòa', N'Truy kích địch đến biên giới', N'Tiêu diệt tàn quân', N'Rút quân về Thăng Long', 0, 1, 0);
INSERT INTO QUESTION VALUES(33, N'Lý Thường Kiệt thọ bao nhiêu tuổi?', N'85', N'86', N'87', N'88', 1, 1, 1);
INSERT INTO QUESTION VALUES(34, N'Tác phẩm sau đây là của Lý Thường Kiệt?', N'Nam Quốc sơn hà', N'Chiếu Xuất Quân', N'Ðại Nam Quốc Sử Diễn Ca', N'Phạt Tống lộ bố văn', 3, 1, 1);
INSERT INTO QUESTION VALUES(35, N'Lý Thường Kiệt hai lần làm Tể tướng dưới triều vua nào?', N'Lý Thánh Tông', N'Lý Nhân Tông', N'Lý Thần Tông', N'Lý Thái Tông', 1, 1, 1);
INSERT INTO QUESTION VALUES(36, N'Lực lượng quân Tống sang xâm lược nước ta gồm bao nhiêu quân?', N'100.000 quân chiến đấu, 200.000 dân phu', N'150.000 quân chiến đấu, 200.000 dân phu', N'100.000 quân chiến đấu, 150.000 dân phu', N'150.000 quân chiến đấu, 150.000 dân phu', 0, 1, 1);
INSERT INTO QUESTION VALUES(37, N'Lực lượng quân Lý do Lý Thường Kiệt chỉ huy ở phòng tuyến Như Nguyệt gồm bao nhiêu?', N'50.000 quân', N'55.000 quân', N'60.000 quân', N'65.000 quân', 2, 1, 1);
INSERT INTO QUESTION VALUES(38, N'Vị tướng nào đã chỉ huy thủy quân nhà Lý đánh bại thủy quân Tống do Hòa Mâu và Dương Tùng Tiên chỉ huy tại vùng biển Đông Kênh, tạo nên thời cơ cho Lý Thường Kiệt đánh bại chủ lực quân Tống ở phía bắc sông Như Nguyệt?', N'Hoằng Chân', N'Lý Kế Nguyên', N'Chiêu Văn', N'Nguyễn Căn', 1, 1, 1);
INSERT INTO QUESTION VALUES(39, N'Tổn thất của quân Tống sau khi xâm lược nước ta?', N'76.600 quân và 8 vạn phu', N'82.200 quân và 8 vạn phu', N'86.600 quân và 9 vạn phu', N'92.200 quân và 9 vạn phu', 0, 1, 1);
--Tran Hung Dao
INSERT INTO QUESTION VALUES(40, N'Tên thật của Trần Hưng Đạo là gì?', N'Trần Quốc Toản', N'Trần Quốc Tuấn', N'Trần Đình Xu', N'Trần Thái Tông', 1, 2, 0);
INSERT INTO QUESTION VALUES(41, N'Trong phần lớn sự nghiệp, ông phụng sự vị vua nào?', N'Trần Thái Tông', N'Trần Thánh Tông', N'Trần Nhân Tông', N'Trần Anh Tông', 1, 2, 0);
INSERT INTO QUESTION VALUES(42, N'Trần Hưng Đạo từng 3 lần dẫn quân đi chống thế lực giặc ngoại xâm nào?', N'Quân Nguyên Mông', N'Quân Minh', N'Quân Thanh', N'Quân Tần', 0, 2, 0);
INSERT INTO QUESTION VALUES(43, N'Trần Hưng Đạo 3 lần dẫn quân chống quân Nguyên Mông xảy ra vào những năm nào?', N'1259, 1285, 1288', N'1258, 1289, 1290', N'1255, 1284, 1287', N'1258, 1285, 1287', 3, 2, 0);
INSERT INTO QUESTION VALUES(44, N'Năm 1285, khi bị quân Nguyên Mông đánh bại, Trần Hưng Đạo đã được vị tướng nào cứu thoát?', N'Dã Tượng', N'Yết Kiêu', N'Trần Quang Khải', N'Phạm Ngũ Lão', 1, 2, 0);
INSERT INTO QUESTION VALUES(45, N'Trong lần đánh thứ hai, ông đã cùng 2 vị tướng nào phản công đại phá quân Nguyên Mông?', N'Trần Quang Khải, Trần Quốc Toản', N'Trần Quang Diệu, Trần Quốc Toản', N'Trần Quang Khải, Trần Nhật Duật', N'Trần Nhật Duật, Trần Quốc Hiến', 2, 2, 0);
INSERT INTO QUESTION VALUES(46, N'Trong lần đánh cuối cùng, khi được vua Trần Nhân Tông hỏi: "Năm nay đánh giặc thế nào?", Hưng Đạo vương đã trả lời thế nào?', N'“Năm nay tuy giặc đông, nhưng quân ta đã được tôi luyên từ trận chiến trước, chiến thắng trong tầm tay”', N'“Quân quý ở tinh nhuệ, không quý ở số đông. Dẫu đến 100 vạn quân mà như Bồ Kiên thì cũng làm gì được?”', N'“Nhờ uy tín của tổ tông và thần võ của bệ hạ, quân ta nhất định sẽ quét được quân địch”', N'"Năm nay đánh giặc nhàn"', 3, 2, 0);
INSERT INTO QUESTION VALUES(47, N'Đâu là trận chiến quyết định trong lần đánh này?', N'Trận Bạch Đằng', N'Trận Vạn Kiếp', N'Trận Vân Đồn', N'Trận Thanh Hóa – Nghệ An', 0, 2, 0);
INSERT INTO QUESTION VALUES(48, N'Trong trận Bạch Đằng, ông đã sử dụng chiến thuật gì để đánh đuổi giặc ngoại xâm?', N'Lợi dụng gió đông, châm lửa đốt thuyền địch', N'Dụ địch vào rừng, đốt rừng và hỏa thiêu quân địch', N'Cho quân cắm cọc gỗ vót nhọn ở đáy sông, tạo thành thế trận cọc ngầm độc đáo', N'Dụ địch vào hẻm núi, cho quân thả đá lớn đè chết địch', 2, 2, 0);
INSERT INTO QUESTION VALUES(49, N'Bao nhiêu thuyền địch đã bị phá hủy?', N'400', N'500', N'600', N'700', 0, 2, 0);
INSERT INTO QUESTION VALUES(50, N'Vua Trần Nhân Tông từng gia phong phong hiệu gì cho Trần Hưng Đạo vào tháng 4 âm lịch năm 1289?', N'Thái sư', N'Tể tướng', N'Đại vương', N'Đại nguyên soái', 2, 2, 0);
INSERT INTO QUESTION VALUES(51, N'Trần Hưng Đạo đã từng sáng tác ra tác phẩm nổi tiếng nào dưới đây?', N'Hịch tướng sĩ', N'Nam quốc sơn hà', N'Tức cảnh Pác Pó', N'Bình Ngô đại cáo', 0, 2, 0);
INSERT INTO QUESTION VALUES(52, N'Trần Hưng Đạo mất năm nào?', N'1297', N'1298', N'1299', N'1300', 3, 2, 0);
INSERT INTO QUESTION VALUES(53, N'Cha của Trần Hưng Đạo tên là gì?', N'Trần Liễu', N'Trần Cận Ngôn', N'Trần Thanh', N'Trần Hưng', 0, 2, 1);
INSERT INTO QUESTION VALUES(54, N'Nơi Trần Hưng Đạo lui về ở ẩn là đâu?', N'Vạn Sơn', N'Vạn Kiếp', N'Vạn Giang', N'Vạn Lâm', 1, 2, 1);
INSERT INTO QUESTION VALUES(55, N'Vợ của Trần Hưng Đạo là ai?', N'Thiên Kim công chúa', N'Thiên Thi công chúa', N'Thiên Minh công chúa', N'Thiên Thành công chúa', 3, 2, 1);
INSERT INTO QUESTION VALUES(56, N'Ai là một trong các gia thần của Trần Hưng Đạo?', N'Dã Tượng', N'Trương Hán Siêu', N'Phạm Ngũ Lão', N'Nguyễn Thế Trực', 0, 2, 1);
INSERT INTO QUESTION VALUES(57, N'Trần Hưng Đạo đã từng gạt bỏ hiền khích với ai để chuyên tâm lo việc nước?', N'Trần Quang Khải', N'Trần Quốc Hiến', N'Trần Nhật Duật', N'Trần Quốc Tung', 0, 2, 1);
INSERT INTO QUESTION VALUES(58, N'Trần Hưng Đạo nổi tiếng với chiến lược nào?', N'Đánh nhanh thắng nhanh', N'Đánh chậm thắng chậm', N'Chờ đợi thời cơ phản công', N'Tấn công và rút lui', 3, 2, 1);
INSERT INTO QUESTION VALUES(59, N'Điền vào chỗ trống trong đoạn trích sau:\n“Ta thường tới bữa quên ăn, nửa đêm vỗ gối, ruột đau như cắt, nước mắt đầm đìa; chỉ giận chưa thể xẻ thịt, lột da, ăn gan, ..... quân thù; dẫu cho trăm thân này phơi ngoài nội cỏ, nghìn xác này gói trong da ngựa, ta cũng cam lòng.”', N'Rút máu', N'Uống máu', N'Chặt đầu', N'Tận diệt', 1, 2, 1);
--Quang Trung
INSERT INTO QUESTION VALUES(60, N'Họ tên gốc của Quang Trung là gì?', N'Nguyễn Quang Bình', N'Nguyễn Huệ', 'Hồ Thơm', N'Bắc Bình Vương', 2, 3, 0);
INSERT INTO QUESTION VALUES(61, N'Tại sao lực lượng Tây Sơn lại nổi dậy tấn công chính quyền Đàng Trong?', N'Lật đổ Chúa Nguyễn, xây dựng chính quyền Tây Sơn', N'Phục tùng vua Lê – Chúa Trịnh, tiêu diệt Đàng Trong', N'Dẹp loạn Đàng Trong – Đàng Ngoài, thống nhất đất nước', N'Lật đổ quyền thần Trương Phúc Loan, phò Hoàng tôn Nguyễn Phúc Dương', 3, 3, 0);
INSERT INTO QUESTION VALUES(62, N'Chỉ trong một ngày, làm cách nào mà vua Quang Trung có thể đánh tan 50 vạn quân Xiêm – Nguyễn tại khúc sông Rạch Gầm – Xoài Mút', N'Lợi dụng gió đông, châm lửa đốt thuyền địch', N'Dụ địch vào địa hình nhỏ hẹp, nhiều rạch nhỏ chảy quanh các cồn cát, kết hợp thủy – bộ, mai phục quân địch', N'Cho quân cắm cọc gỗ vót nhọn ở đáy sông, tạo thành thế trận cọc ngầm độc đáo', N'Dụ thuyền địch tiến quân sát đất liền, lợi dụng thủy triều xuống, thuyền địch mắc cạn, quân ta nhảy ra mai phục', 1, 3, 0);
INSERT INTO QUESTION VALUES(63, N'Cuộc nội chiến Tây Sơn – Chúa Trịnh đã dẫn đến mâu thuẫn nào?', N'Tây Sơn – Nhân dân Đàng Ngoài', N'Thế chân vạc Nguyễn Ánh – Tây Sơn – Chúa Trịnh', N'Nhân dân Đàng Trong – Đàng Ngoài', N'Nội bộ Tây Sơn', 3, 3, 0);
INSERT INTO QUESTION VALUES(64, N'Quyết định sáng suốt nào của nhà Tây Sơn đã làm bàn đạp cho cuộc đại phá quân Thanh?', N'Dùng chiến thuật “Vườn không nhà trống”, bỏ thành Thăng Long', N'Sai Ngô Văn Sở hợp sức với Vũ Văn Nhậm mang quân ra Bắc', N'Nguyễn Huệ lên ngôi Hoàng đế', N'Bắc tiến thần tốc', 0, 3, 0);
INSERT INTO QUESTION VALUES(65, N'Chiến thuật nào là đỉnh cao nhất trong chiến thắng đại phá quân Thanh?', N'Bỏ thành Thăng Long “Vườn không nhà trống”', N'Cho quân sĩ ăn Tết, động viên quân sĩ trước khi ra quân', N'Tiến quân thần tốc, kết hợp vừa gấp gáp vừa thư thả, giương đông kích tây, tránh chỗ mạnh nhằm chỗ yếu', N'Chuẩn bị quân lực, quân lương cẩn thận, dùng người hợp lí', 2, 3, 0);
INSERT INTO QUESTION VALUES(66, N'Ai là người đã hiến kế giúp vua Quang Trung đại phá quân Thanh?', N'Nguyễn Thiếp', N'Ngô Thì Nhậm', N'Vũ Văn Nhậm', N'Ngô Văn Sở', 0, 3, 0);
INSERT INTO QUESTION VALUES(67, N'Vua Quang Trung quê gốc ở đâu?', N'Gia Định', N'Huế', N'Bình Định', N'Nghệ An', 3, 3, 0);
INSERT INTO QUESTION VALUES(68, N'Có tổng cộng bao nhiêu đồn bị hạ trong trận đại phá quân Thanh?', '8', '7', '6', '5', 1, 3, 0);
INSERT INTO QUESTION VALUES(69, N'Hịch đánh Thanh có tên là “Lời hiểu dụ tướng sĩ” được vua Quang Trung đọc tại lễ lên ngôi Hoàng đế:“Đánh cho để dài tóc\nĐánh cho để đen răng\nĐánh cho nó chích luân bất phản\nĐánh cho nó phiến giáp “ ...“\nĐánh cho sử tri Nam quốc anh hùng chi hữu chủ”\n\n Phần còn thiếu là', N'Bất hoàn', N'Bất di', N'Bất phục', N'Bất cam', 0, 3, 0);
INSERT INTO QUESTION VALUES(70, N'Nguyễn Huệ sinh vào năm nào?', '1753', '1755', '1754', '1752', 0, 3, 0);
INSERT INTO QUESTION VALUES(71, N'Võ phái Bình Định nào không phải do 3 anh em Tây Sơn khai sáng?', N'Yến phi quyền', N'Hùng kê quyền', N'Túy quyền', N'Độc lư thương', 2, 3, 0);
INSERT INTO QUESTION VALUES(72, N'Năm 1775, tình thế của quân Tây Sơn lúc đó rất nguy ngập khi phải đối đâu với Chúa Nguyễn và Trịnh, Nguyễn Nhạc đã quyết định làm gì?', N'Mang quân đương đầu với cả 2 phía', N'Giảng hòa  với Chúa Trịnh, tập trung vào chiến trường phía Nam', N'Giảng hòa với Chúa Nguyễn, tập trung vào chiến trường phía Bắc', N'Án binh bất động', 1, 3, 0);
INSERT INTO QUESTION VALUES(73, N'Bị quân Tây Sơn truy sát, Nguyễn Ánh sang Xiêm cầu viện ai?', N'Rama II', N'Rama IV', N'Rama III', N'Rama I', 3, 3, 1);
INSERT INTO QUESTION VALUES(74, N'Nguyễn Huệ mất bao lâu để đánh tan 50 vạn quân Xiêm – Nguyễn trong trận Rạch Gầm – Xoài Mút?', N'2 ngày', N'5 ngày', N'1 ngày', N'3 ngày', 2, 3, 1);
INSERT INTO QUESTION VALUES(75, N'Chiến tranh Trịnh-Tây Sơn kết thúc với chiến dịch nào?', N'Thăng Long 1786', N'Phú Xuân 1786', N'Thăng Long 1789', N'Phú Xuân 1785', 0, 3, 1);
INSERT INTO QUESTION VALUES(76, N'Nguyễn Huệ và Nguyễn Nhạc có xảy ra mâu thuẫn và đem quân đánh nhau vào năm nào?', '1785', '1788', '1786', '1787', 3, 3, 1);
INSERT INTO QUESTION VALUES(77, N'Nguyễn Huệ lên ngôi hoàng đế ở nơi nào?', N'Huế', N'Gia Định', N'Thăng Long', 'Nghệ An', 0, 3, 1);
INSERT INTO QUESTION VALUES(78, N'Vua Quang Trung từng 4 lần hạ cố mời ai ra giúp nước?', N'Ngô Thì Nhậm', N'Nguyễn Thiếp', N'Trương Văn Hiến', N'Lê Hiển Tông', 2, 3, 1);
INSERT INTO QUESTION VALUES(79, N'Mất bao nhiêu ngày để quân Tây Sơn hành quân thần tốc đến kinh thành Thăng Long đánh tan 29 vạn quân Thanh?', N'40 ngày', N'20 ngày', N'10 ngày', N'5 ngày', 3, 3, 1);
-- Ho Chi Minh
INSERT INTO QUESTION VALUES(80, N'Lý do chủ yếu nhất Pháp cử Na-va sang Đông Dương?', N'Vì sau chiến tranh Triều Tiên Mĩ muốn tăng cường can thiệp vào Đông Dương', N'Vì Na-va được Mĩ chấp thuận', N'Vì phong trào phản đối chiến tranh của nhân dân Pháp lên cao', N'Sau 8 năm tiến hành chiến tranh Pháp sa lầy, vùng chiếm đóng bị thu hẹp có nhiều khó khăn về kinh tế tài chính', 3, 4, 0);
INSERT INTO QUESTION VALUES(81, N'Âm mưu của Pháp, Mĩ trong việc vạch ra kế hoạch quân sự Na-va', N'Lấy lại thế chủ động trên chiến trường chính Bắc Bộ', N'Xoay chuyển cục diện chiến tranh Đông Dương trong 18 tháng hi vọng “kết thúc chiến tranh trong danh dự', N'Giành thắng lợi quân sự kết thúc chiến tranh trong vòng 18 tháng', N'Giành thắng lợi quân sự kết thúc chiến tranh theo ý muốn', 1, 4, 0);
INSERT INTO QUESTION VALUES(82, N'Phương châm chiến lược của ta trong Đông-Xuân 1953-1954 là gì?', N'“Đánh nhanh, thắng nhanh”', N'“Đánh chắc, thắng chắc”', N'“Đánh vào những nơi ta cho là chắc thắng”', N'"Tích cực, chủ động, cơ động, linh hoạt", “Đánh ăn chắc Đánh chắc thắng”', 3, 4, 0);
INSERT INTO QUESTION VALUES(83, N'Nơi nào diễn ra trận chiến đấu giằng co và ác liệt nhất trong chiến dịch Điện Biên Phủ', N'Cứ điểm Him Lam', N'Sân bay Mường Thanh', N'Đồi A1', N'Sở chỉ huy Đờ Cát-tơ- ri', 2, 4, 0);
INSERT INTO QUESTION VALUES(84, N'Ý nghĩa cơ bản nhất của chiến thắng lịch sử Điện Biên Phủ 1954 là gì?', N'Thắng lợi lớn nhất, oanh liệt nhất tiêu biểu cho tinh thần chiến đấu anh hùng, bất khuất của dân tộc ta', N'Được ghi vào lịch sử dân tộc như một Bạch Đằng, một Chi Lăng, một Đống Đa của thế kỉ XX', N'Góp phần làm tan rã hệ thống thuộc địa của chủ nghĩa đế quốc', N'Cỗ vũ các dân tộc bị áp bức đứng lên tự đấu tranh giải phóng mình', 0, 4, 0);
INSERT INTO QUESTION VALUES(85, N'Tháng 8 - 1954, ở Sài Gòn diễn ra', N'Phong trào hòa bình', N'Phong trào chống tố cộng-diệt cộng',N'Phong trào chống trưng cầu dân ý', N'Phong trào chống bầu cử quốc hội', 0, 4, 0);
INSERT INTO QUESTION VALUES(86, N'Nội dung nào Không phải là mục tiêu cuộc đấu tranh của nhân dân miền Nam trong những ngày đầu chống Mĩ - Diệm?', N'Đòi thi hành hiệp định Giơnevơ', N'Bảo vệ hòa bình', N'Giữ gìn và phát triển lực lượng', N'Lật đổ chính quyền Mĩ - Diệm', 3, 4, 0);
INSERT INTO QUESTION VALUES(87, N'Điểm khác nhau giữa “Chiến tranh đặc biệt” và “Việt Nam hóa chiến tranh” là gì?', N'Hình thức chiến tranh thực dân mới của Mỹ', N'Có sự phối hợp đáng kể của lực lượng chiến đấu Mỹ', N'Dưới sự chỉ huy của hệ thống cố vấn quân sự Mỹ', N'Sử dụng lực lượng chủ yếu là quân nguỵ', 1, 4, 0);
INSERT INTO QUESTION VALUES(88, N'Thắng lợi của cuộc kháng chiến chống Mĩ cứu nước có ý nghĩa quốc tế là', N'Tác động đến tình hình thế giới', N'Làm thay đổi cục diện chính trị thế giới', N'Tác động đến nước Mĩ và thế giới', N'Tác động đến nước Mĩ và thế giới, cổ vũ phong trào cách mạng thế giới', 3, 4, 0);
INSERT INTO QUESTION VALUES(89, N'Thắng lợi lớn nhất của quân và dân miền Bắc trong trận “Điện Biên Phủ trên không” là gì?', N'Buộc Mĩ kí hiệp định Pa-ri về chấm dứt chiến tranh lập lại hòa bình ở Việt Nam', N'Buộc Mĩ phải tuyên bố ngừng hán các hoạt độríg chống phá miền Bắc', N'Đánh bại âm mưu phá hoại công cuộc xây dựng CNXH ở miền Bắc', N'Đánh bại âm mưu ngăn chặn sự chi viện của miền Bắc cho miền Nam, Lào, Campuchia', 0, 4, 0);


--PROCEDURE
-- Sign up
--Đăng ký 1 tài khoản vào DB
Go
CREATE PROCEDURE sp_SignUp @username nchar(15)
AS
BEGIN
	DECLARE @maxPlayerID int

	SET @maxPlayerID =  (SELECT MAX(PlayerID) FROM PLAYER)
	
	IF (@maxPlayerID IS NULL)
	BEGIN
		SET @maxPlayerID = -1;
	END

	DECLARE @maxSceneID int
	SET @maxSceneID = (Select MAX(SceneID) FROM SCENE)

	INSERT INTO PLAYER VALUES(@maxPlayerID + 1, @username, 0, 0);
	
	DECLARE @i int;
	SET @i = 0;
	
	WHILE (@i <= @maxSceneID)
	BEGIN
		INSERT INTO RESULT VALUES(@maxPlayerID + 1, @i, 0, 0);
		SET @i = @i + 1;
	END
END

Go
--LOAD LIST USER
--Load danh sách username có sẵn trong DB
CREATE PROCEDURE sp_LoadListPlayer
AS
BEGIN
	SELECT * FROM PLAYER
END

Go
--LOGIN
--Đăng nhập vào 1 tài khoản có sẵn trong DB, load lịch sử các màn chơi 1 lần duy nhất trước khi login
CREATE PROCEDURE sp_Login @playerID int
AS
BEGIN
	SELECT P.PlayerID, P.TotalScore, P.Username, P.GameLife, R.SceneID, R.Score, R.isCompleted 
	FROM PLAYER P, RESULT R 
	WHERE P.PlayerID = @playerID AND R.PlayerID = @playerID
END

Go
--LOAD QUESTION
--Load câu hỏi 1 lần duy nhất khi mới vào game
CREATE PROCEDURE sp_LoadQuestion
AS
BEGIN
	SELECT * FROM QUESTION
END

Go
--LOAD INFO PLAYER
CREATE PROCEDURE sp_LoadInfoPlayer @playerID int
AS
BEGIN
	SELECT * FROM RESULT WHERE PlayerID = @playerID
END

Go
--LOAD RANK
--Hiển thị bảng xếp hạng người dùng
CREATE PROCEDURE sp_LoadRank
AS
BEGIN
	SELECT Username, TotalScore FROM PLAYER ORDER BY TotalScore DESC
END

Go
--UPDATE Status
--Cập nhật lại Score, TotalScore, isComplete của màn chơi đó
CREATE PROCEDURE sp_UpdateStatus @playerID int, @score int, @sceneID int, @isCompleted bit
AS
BEGIN
	DECLARE @oldScore int
	SET @oldScore = (SELECT Score FROM RESULT  WHERE SceneID = @sceneID AND PlayerID = @playerID)

	UPDATE RESULT
	SET Score = @score, isCompleted = @isCompleted
	WHERE PlayerID = @playerID AND SceneID = @sceneID

	UPDATE PLAYER
	SET TotalScore = TotalScore - @oldScore + @score
	WHERE PlayerID = @playerID
END

Go
--DELETE PLAYER
--Xóa player và các thông tin liên quan như bảng RESULT
CREATE PROCEDURE sp_DeletePlayer @playerID int
AS
BEGIN
	DELETE FROM RESULT WHERE PlayerID = @playerID
	DELETE FROM PLAYER WHERE PlayerID = @playerID
END

SELECT *
FROM PLAYER

SELECT Question,RightAnswer
FROM QUESTION
WHERE SceneID = 2

SELECT Question,AnswerA,AnswerB,AnswerC,AnswerD,RightAnswer,isBonus
FROM QUESTION
WHERE SceneID = 4

UPDATE QUESTION
SET isBonus = 0
WHERE QuestionID = 19

UPDATE QUESTION
SET SceneID = 1
WHERE QuestionID >= 40 AND QuestionID <= 59

UPDATE QUESTION
SET SceneID = 2
WHERE QuestionID >= 60 AND QuestionID <= 79

UPDATE QUESTION
SET SceneID = 3 
WHERE QuestionID >=20 AND QuestionID <= 39

UPDATE SCENE
Set SceneName = N'Trần Hưng Đạo'
WHERE SceneID = 1

UPDATE SCENE
Set SceneName = N'Quang Trung'
WHERE SceneID = 2

UPDATE SCENE
Set SceneName = N'Lý Thường Kiệt'
WHERE SceneID = 3

UPDATE SCENE
Set SceneName = N'Hồ Chí Minh'
WHERE SceneID = 4
