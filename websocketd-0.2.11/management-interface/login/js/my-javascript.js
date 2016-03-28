function setCookie(cname,cvalue,exdays) {
    var d = new Date();
    d.setTime(d.getTime() + (exdays*24*60*60*1000));
    //d.setTime(d.getTime() + (exdays*1000));
    var expires = "expires=" + d.toGMTString();
    document.cookie = cname+"="+cvalue+"; "+expires+ "; path=/";
}

function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1);
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function isToken(buff) {
    var check = buff.substr(0, 5);
    var n = check.localeCompare("token");
    if ( n == 0) {
        buff = buff.substr(6, buff.length);
        if (!buff || 0 === buff.length) {
            return -1;
        }
        else {
            return 0;
        }
    }
    else {
        return -1;
    }
}

