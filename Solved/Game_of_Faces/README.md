# Game of Faces
Web

## Challenge 

The Game of Faces, welcomes you. In this era, where AIs generate a lot of faces, we would like you to contribute to the same by uploading your image. Thank you for contributing, to continue.

http://159.89.166.12:15000/

## Solution

The page merely shows random colored boxes

If we look at the source code, we see a hidden form

    <div class="form_img" >
		<form action='#' method = "GET" target="resultFrame">
		  Upload Your Profile Picture : <input type="file" name="profile_pic" >
		  <input type="submit" value="Upload Image" name="submit">
		</form>
    </div>

If we click on the hidde submit button we are redirected to this page

http://159.89.166.12:15000/?profile_pic=&submit=Upload+Image#

On the page we see the text

	Ah! One more day, One more fake hacker
	Upload Your Profile Picture : 
	VGhlX3Njcm9sbF9zYXlzPXRoZV9uaWdodF9raW5nVlN2YWx5cmlhbi50eHQ==

Decode it

	$ echo 'VGhlX3Njcm9sbF9zYXlzPXRoZV9uaWdodF9raW5nVlN2YWx5cmlhbi50eHQ==' | base64 -D
	The_scroll_says=the_night_kingVSvalyrian.txt

And then visit the page to see the flag

http://159.89.166.12:15000/the_night_kingVSvalyrian.txt

## Flag

	pctf{You_L00K_Wi3Rd_IN_H3R3}
