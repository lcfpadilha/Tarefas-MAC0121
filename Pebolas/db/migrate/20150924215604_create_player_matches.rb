class CreatePlayerMatches < ActiveRecord::Migration
  def change
    create_table :player_matches do |t|

      t.timestamps null: false
    end
  end
end
