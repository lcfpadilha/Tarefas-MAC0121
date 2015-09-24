class Player < ActiveRecord::Base
	def facebook
		@facebook ||= Koala::Facebook::API.new(oauth_token)
	end
end
