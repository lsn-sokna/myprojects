//this code will run on javascript console only
/* how to use this code
 1. you have to open status, comment, photo or whatever you want to share
 2. Inspect Element and then go to console
 3. Paste the code
 4. Press Enter
 5. You have to wait until CAPTCHA Dialog pop up
 6. After 20mn later, you can run this code again and start 1st step.
 *Warning: Be aware of CAPTCH or you'll be blocked from sharing feature.
 Thanks you!
 Coded by Sokna Ly
*/
//get fb_dtsg
var fb_dtsg=document.getElementsByName("fb_dtsg")[0].value;
//get user_id from cookie
var user_id=document.cookie.match(document.cookie.match(/c_user=(\d+)/)[1]);
//get share button from facebook by getting across some elements
var href=decodeURIComponent(document.getElementsByClassName("UIActionLinks UIActionLinks_bottom")[0].getElementsByTagName("a")[1].getAttribute("href"));
//if it doesn't work just change "getElementsByTagName("a")[1]" to "getElementsByTagName("a")[2]"

var appid=href.substring(24,34);
var att0=href.substring(40,55);
var att1=href.substring(61,71);
var count=0;
function auto_share(){
	var http= new XMLHttpRequest();
	var params="";
	params+="fb_dtsg="+fb_dtsg;
	params+="&ad_params=";
	params+="&mode=self";
	params+="&friendTarget=";
	params+="&groupTarget=";
	params+="&message_text=";
	params+="&message=";
	params+="&attachment[params][0]="+att0;
	params+="&attachment[params][1]="+att1;
	params+="&attachment[type]=2";
	params+="&share_source_type=unknown";
	params+="&src=i";
	params+="&appid="+appid;
	params+="&parent_fbid=";
	params+="&ogid=";
	params+="&audience[0][value]=10";
	params+="&__user="+user_id;
	params+="&__a=1";
	params+="&__dyn=7n8apij2qmqDzpQ9UoHaHyG8qeyp9Esx6iWF3qGEVd4WpU";
	params+="&__req=16";
	params+="&ttstamp=2658166681025585111";
	params+="&__rev=1132776";
	http.open("POST","/ajax/sharer/submit/",true);
	http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	http.onreadystatechange=	function(){
        if(http.readyState == 4 && http.status == 200) {
            http.close;
        };
    };
	http.send(params);
	count++;
	
};
var startSharing=setInterval(auto_share,3000);
if(count==100)
clearInterval(startSharing);
